#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool disable[31]={0,};
vector<int> v[31];
int maxNum=0;
int answer;

void dfs(int length, vector<int> ans,int num)
{
    if(length==5)
    {
        bool correct=true;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]!=0)
            {
                correct=false;
                break;
            }
        }
        
        if(correct)
            answer++;
        return;
    }
    
    for(int i=num;i<=maxNum;i++)
    {
        if(disable[i])
            continue;
        
        bool possible=true;
        vector<int> copy=ans;
        for(int j=0;j<v[i].size();j++)
        {
            if(ans[v[i][j]]<=0)
            {
                possible=false;
                break;
            }
            else
            {
                copy[v[i][j]]--;
            }
        }
    
        if(possible)
        {
            dfs(length+1,copy,i+1);
        }
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    answer = 0;
    
    maxNum = n;
    for(int i=0;i<q.size();i++)
    {
        for(int j=0;j<5;j++)
        {
            int num= q[i][j];
            if(!disable[num] && ans[i]!=0)
            {
                v[num].push_back(i);
            }
            else if(ans[i]==0)
            {
                v[num].clear();
                disable[num]=true;
            }
        }
    } // 벡터 생성

    dfs(0,ans,1);
    
    return answer;
}