#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string,int> combination;
int maxOrder=0;

bool comapre(string a,string b)
{

    return a<b;
}
    

void dfs(string order, int length, string str, int index)
{
    if(length == str.length())
    {
        combination[str]++;
        return;
    }
    
    for(int i=index;i<order.length();i++)
    {
        dfs(order,length,str+order[i],i+1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int single : course)
    {
        maxOrder=0;
        for(string order : orders)
        {
            sort(order.begin(),order.end());
            dfs(order,single,"",0);
        }
        
        for (auto iter: combination) 
        {
            maxOrder = max(maxOrder, iter.second);
        }
        
         for (auto iter: combination) 
         {
             if(maxOrder == iter.second && maxOrder>=2)
             {
                 answer.push_back(iter.first);
             }
         }
        combination.clear();
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}