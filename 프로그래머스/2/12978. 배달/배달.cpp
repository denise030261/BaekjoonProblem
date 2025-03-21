#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    int distance[51]={0,};
    bool visited[51]={0,};
    vector<pair<int,int>> v[N+1];
    priority_queue<pair<int,int>> pq;
    
    for(int i=0;i<=N;i++)
    {
        distance[i]=INT_MAX;
    }
    for(int i=0;i<road.size();i++)
    {
        v[road[i][0]].push_back({road[i][1],road[i][2]});
        v[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    
    
    visited[1]=true;
    distance[1]=1;
    pq.push({-0, 1});
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int target = pq.top().second;
        pq.pop();
        
        for(int i=0;i<v[target].size();i++)
        {
            if(distance[v[target][i].first]>v[target][i].second+cost)
            {
                visited[v[target][i].first]=true;
                distance[v[target][i].first] = v[target][i].second+cost;
                pq.push({-(v[target][i].second+cost), v[target][i].first});
            }
        }
    }
    
    for(int i=1;i<=N;i++)
    {
        if(distance[i]<=K)
            answer++;
    }

    return answer;
}