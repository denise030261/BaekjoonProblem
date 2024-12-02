#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;
vector<int> infov;
vector<int> v[17];

void dfs(int current,int sheep, int wolf,queue<int> q)
{
    if(infov[current]==0)
        sheep++;
    else
        wolf++;
    
    if(sheep<=wolf)
        return;
    
    answer=max(answer,sheep);
    
    for(int i=0;i<v[current].size();i++)
    {
        q.push(v[current][i]);
    }
    
    for(int i=0;i<q.size();i++)
    {
        int next=q.front();
        q.pop();
        dfs(next,sheep,wolf,q);
        q.push(next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    queue<int> q;
    
    infov.assign(info.begin(),info.end());
    for(int i=0;i<edges.size();i++)
    {
        v[edges[i][0]].push_back(edges[i][1]);
    }
    
    dfs(0,0,0,q);
    
    return answer;
}