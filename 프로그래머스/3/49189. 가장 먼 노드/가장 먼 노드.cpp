#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    int maxNum=0;
    bool visited[20001]={0,};
    int answers[20001]={0,};
    vector<int> connect[20001];
    priority_queue<pair<int,int>> pq;
    
    for(int i=0;i<edge.size();i++)
    {
        connect[edge[i][0]].push_back(edge[i][1]);
        connect[edge[i][1]].push_back(edge[i][0]);
    }
    
    pq.push({0,1});
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int node = pq.top().second;
        visited[node]=true;
        answers[node] = cost;
        pq.pop();
        for(int i=0;i<connect[node].size();i++)
        {
            if(!visited[connect[node][i]])
            {
                visited[connect[node][i]]=true;
                answers[connect[node][i]] = cost+1;
                pq.push({-(cost+1),connect[node][i]});
                maxNum=max(maxNum,cost+1);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(answers[i]==maxNum)
            answer++;
    }
    
    return answer;
}