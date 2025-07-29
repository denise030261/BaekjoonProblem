#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,pair<string,string>>> data;
    
    for(int i=0;i<record.size();i++)
    {
        istringstream ss (record[i]);
        string subs1; 
        vector<string> v;
        while(getline(ss,subs1,' '))
        {
            v.push_back(subs1);
        }
        
        if(v[0]=="Leave")
        {
            data.push_back({v[0],{v[1],""}});
        }
        else
        {
            data.push_back({v[0],{v[1],v[2]}});
        }
    }
    
    map<string,string> m;
    for(int i=record.size()-1;i>=0;i--)
    {
        if((data[i].first=="Enter" && m.find(data[i].second.first) == m.end())
           || (data[i].first=="Change" && m.find(data[i].second.first) == m.end()))
        {
            m.insert({data[i].second.first, data[i].second.second});
        }
    }
    
    for(int i=0;i<record.size();i++)
    {
        string say = data[i].first;
        string id = data[i].second.first;
        string name = m[id];
        
        if(say=="Enter")
        {
            answer.push_back(name+"님이 들어왔습니다.");
        }
        else if(say=="Leave")
        {
            answer.push_back(name+"님이 나갔습니다.");
        }
    }
    return answer;
}