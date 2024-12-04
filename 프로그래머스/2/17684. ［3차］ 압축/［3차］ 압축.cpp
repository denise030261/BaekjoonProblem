#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> m;
    for(int i=0;i<26;i++)
    {
        char content = 'A'+i;
        string str;
        str+=content;
        m.insert({str,i+1});
    }
    
    string saveStr ="";
    for(int i=0;i<msg.length();i++)
    {
        string addStr;
        addStr+=msg[i];
        if(m.find(saveStr+addStr)!=m.end())
        {
            saveStr+=addStr;
        }
        else if(m.find(saveStr)!=m.end())
        {
            answer.push_back(m[saveStr]);
            saveStr+=addStr;
            m.insert({saveStr,m.size()+1});
            saveStr=addStr;
        }
    }
    
    if(m.find(saveStr)!=m.end())
    {
        answer.push_back(m[saveStr]);
    }
    
    return answer;
}