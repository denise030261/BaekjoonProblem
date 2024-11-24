#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) 
{ 
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    
    bool bAllZero=true;
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i]!=0)
            bAllZero=false;
        str.push_back(to_string(numbers[i]));
    }
    sort(str.begin(),str.end(),compare);
    
    if(bAllZero)
        return "0";
    
    for(int i=0;i<str.size();i++)
        answer+=str[i];

    return answer;
}