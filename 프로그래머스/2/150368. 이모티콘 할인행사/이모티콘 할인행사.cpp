#include <string>
#include <vector>
#include <iostream>

using namespace std;

int discountCost[7]={0,};
int discount[4]={10,20,30,40};
vector<int> emoticon;
vector<vector<int>> user;
int maxJoin=0;
int maxCost=0;

void dfs(int length)
{

    if(length!=emoticon.size())
    {
        for(int i=0;i<4;i++)
        {
            discountCost[length]=discount[i];
            dfs(length+1);
        }
        
        return;
    }
    
    int join=0;
    int cost=0;
    
    for(int i=0;i<user.size();i++)
    {
        int sum=0;
        for(int j=0;j<emoticon.size();j++)
        {
            if(discountCost[j]>=user[i][0])
            {
                sum+=emoticon[j]*(100-discountCost[j])/100.0;
            }
        }
        
        if(sum>=user[i][1])
        {
            join++;
        }
        else
        {
            cost+=sum;
        }
    }
    
    if((join>maxJoin) || (join==maxJoin && cost>maxCost))
    {
        maxJoin=join;
        maxCost=cost;
    }
    
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    emoticon=emoticons;
    user=users;
    
    dfs(0);
    
    answer.push_back(maxJoin);
    answer.push_back(maxCost);
    return answer;
}