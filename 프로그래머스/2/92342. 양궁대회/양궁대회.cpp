#include <string>
#include <vector>
#include <iostream>

using namespace std;

int score[11]={10,9,8,7,6,5,4,3,2,1,0};
int totalArrow=0;
int answerSum=-1;
vector<int> answer;
vector<int> lion;
vector<int> peach;

void dfs(int num,int length)
{
    if(length==totalArrow)
    {
        int lionSum=0;
        int peachSum=0;
        for(int i=10;i>=0;i--)
        {
            if(lion[i]<=peach[i] && peach[i]!=0)
            {
                peachSum+=score[i];
            }
            else if(lion[i]>peach[i] &&lion[i]!=0)
            {
                lionSum+=score[i];
            }
        }
        
        if(peachSum<lionSum && answerSum<(lionSum-peachSum))
        {
            answerSum=lionSum-peachSum;
            answer=lion;
        }
        
        return;
    }
    
    for(int i=num;i>=0;i--)
    {
        lion[i]++;
        dfs(i,length+1);
        lion[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    totalArrow=n;
    peach=info;
    for(int i=0;i<11;i++)
    {
        lion.push_back(0);
    }
    
    dfs(10,0);
    
    if(answerSum==-1)
    {
        answer.clear();
        answer.push_back(-1);
    }
    
    return answer;
}