#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string slice(string str, int term)
{
    int year = stoi(str.substr(0,4));
    int month = stoi(str.substr(5,2));
    int date = stoi(str.substr(8,2));
    
    date--;
    if(date<=0)
    {
        date+=28;
        month--;
    }
    if(month<=0)
    {
        month+=12;
        year--;
    }
    
    month+=term;
    if(month>12)
    {
        year+=month/12;
        month-=12*(month/12);
    }
    if(month<=0)
    {
        month+=12;
        year--;
    }
    
    string str_year = to_string(year);
    string str_month = to_string(month);
    string str_date = to_string(date);
    
    if(month<10)
        str_month = '0'+to_string(month);
    if(date<10)
        str_date = '0'+to_string(date);
    
    return str_year+'.'+str_month+'.'+str_date;
} 

bool Break(string today, string term)
{
    if(stoi(today.substr(0,4))>stoi(term.substr(0,4)))
        return true;
    else if(stoi(today.substr(0,4))<stoi(term.substr(0,4)))
        return false;
    else if(stoi(today.substr(5,2))>stoi(term.substr(5,2)))
        return true;
    else if(stoi(today.substr(5,2))<stoi(term.substr(5,2)))
        return false;
    else if(stoi(today.substr(8,2))>stoi(term.substr(8,2)))
        return true;

    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    for(int i=0;i<privacies.size();i++)
    {
        string date = privacies[i].substr(0,10);
        char info = privacies[i].back();
        
        for(int j=0;j<terms.size();j++)
        {
            if(terms[j][0]==info)
            {
                privacies[i] = slice(privacies[i],stoi(terms[j].substr(terms[j].find(" ")+1)));
                break;
            }
        }
        
        if(Break(today,privacies[i]))
        {
            answer.push_back(i+1);
        }
    }
    return answer;
}