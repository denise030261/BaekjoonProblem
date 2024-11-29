#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10000]={0,};

void dfs(vector<vector<string>> tickets, vector<string> expect,string depart)
{
    if(tickets.size()==expect.size())
            {
                for(int i=0;i<expect.size();i++)
                {
                    answer.push_back(expect[i]);
                }
        answer.push_back(depart);
                return;
            }
    
    for(int i=0;i<tickets.size();i++)
    {
        if(tickets[i][0]==depart && !visited[i] && tickets.size()+1!=answer.size())
        {
            expect.push_back(depart);
            string arrive=tickets[i][1];
            visited[i]=true;
            dfs(tickets,expect,arrive);
            visited[i]=false;
            expect.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(),tickets.end());
    vector<string> expect;
    
    for(int i=0;i<tickets.size();i++)
    {
        if(tickets[i][0]=="ICN" && !visited[i] && tickets.size()+1!=answer.size())
        {
            expect.push_back("ICN");
            string arrive=tickets[i][1];
            visited[i]=true;
            dfs(tickets,expect,arrive);
            visited[i]=false;
             expect.pop_back();
        }
    }
    return answer;
}