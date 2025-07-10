#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++)
    {
        q.push({priorities[i],i});
    }
    sort(priorities.begin(),priorities.end(),greater<int>());
    
    vector<int> process;
    int index=0;
    while(!q.empty())
    {
        if(priorities[index]==q.front().first)
        {
            process.push_back(q.front().second);
            q.pop();
            index++;
        }
        else
        {
            int num=q.front().first;
            int idx=q.front().second;
            q.pop();
            q.push({num,idx});
        }
    }
    
    for(int i=0;i<process.size();i++)
    {
        if(process[i]==location)
        {
            answer=i+1;
            break;
        }
    }
    
    return answer;
}