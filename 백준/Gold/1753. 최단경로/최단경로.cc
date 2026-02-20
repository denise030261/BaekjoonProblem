#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int V, E, K;
    int dist[20001] = { 0, };
    vector<pair<int, int>> arr[20001];
    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({ v,w });
    }

    for (int i = 1; i <= V; i++)
    {
        dist[i] = INF;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ -0,K });
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] <= cost)
        {
            continue;
        }
        dist[cur] = cost;

        for (int i = 0; i < arr[cur].size(); i++)
        {
            int next = arr[cur][i].first;
            int next_cost = arr[cur][i].second;

            if (dist[next] > next_cost + cost)
            {
                pq.push({ -(next_cost + cost),next });
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }
}