#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string changeLow(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]=tolower(str[i]);
        }
    } 
    
    return str;
}

vector<string> div(string str)
{
    vector<string> v;

    bool one=false;
    for(int i=0;i<str.length()-1;i++)
    {
        if((str[i]>='a' && str[i]<='z') &&(str[i+1]>='a' && str[i+1]<='z'))
        {
            string s="";
            s+=str[i];
            s+=str[i+1];
            v.push_back(s);
        }
    }

    return v;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1=changeLow(str1);
    str2=changeLow(str2);
    
    int length=max(str1.length(),str2.length());
    vector<string> v1=div(str1);
    vector<string> v2=div(str2);
    
    map<string,int> m1;
    map<string,int> m2;
    for(int i=0;i<v1.size();i++)
    {
        m1[v1[i]]++;
    }
    for(int i=0;i<v2.size();i++)
    {
        m2[v2[i]]++;
    }
    
    int sum=0;
    int overlap=0;
    
    for (auto iter = m1.begin() ; iter !=  m1.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
        if(m2[iter->first]!=0)
        {
            sum+=max(m1[iter->first],m2[iter->first]);
            overlap+=min(m1[iter->first],m2[iter->first]);
        }
        else
        {
            sum+=m1[iter->first];
        }
    }
    for (auto iter = m2.begin() ; iter !=  m2.end(); iter++)
    {
        if(m1[iter->first]==0)
        {
            sum+=m2[iter->first];
        }
    }

    cout << overlap << ' ' << sum;
    if(sum==0)
        return 65536;
    answer=overlap*65536/sum;

    return answer;
}