#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<string> a,vector<string> b)
{
    return a[1]<b[1];
}

int change(char a,char b)
{
    string str;
    str+=a;
    str+=b;
    return stoi(str);
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(),compare); // 시작 시간 오름차순
    stack<pair<string,int>> s;
    
    for(int i=0;i<plans.size()-1;i++)
    {
        int hour=change(plans[i][1][0], plans[i][1][1]);
        int minute = change(plans[i][1][3], plans[i][1][4]);
        
        int next_hour=change(plans[i+1][1][0], plans[i+1][1][1]);
        int next_minute= change(plans[i+1][1][3], plans[i+1][1][4]);
        
        int doing=0;
        if(next_minute<minute)
        {
            doing+=next_minute+60-minute;
            next_hour--;
        }
        else
        {
            doing+=next_minute-minute;
        }
        doing +=(next_hour-hour)*60;
        
        if(doing>=stoi(plans[i][2]))
        {
            answer.push_back(plans[i][0]);
            doing-=stoi(plans[i][2]);
            
            while(doing!=0 && !s.empty())
            {
                string assignment = s.top().first;
                int time = s.top().second;
                s.pop();
                
                if(doing>=time)
                {
                    doing-=time;
                    answer.push_back(assignment);
                }
                else
                {
                    time-=doing;
                    s.push({assignment,time});
                    break;
                }
            }
        }
        else
        {
            s.push({plans[i][0], stoi(plans[i][2])-doing});
        }
    }
    
    answer.push_back(plans[plans.size()-1][0]);
    
    while(!s.empty())
    {
        answer.push_back(s.top().first);
        s.pop();
    }
    return answer;
}