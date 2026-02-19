#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, E;
    int dist[801][801] = { 0, };
    vector<pair<int, int>> v[801];
    
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            dist[i][j] = 98765432;
        }
    }

    int v1, v2;
    cin >> v1 >> v2;

    priority_queue<pair<int, int>> pq;
    pq.push({ -0,1 });
    bool visited[801] = { 0, };
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (visited[cur])
        {
            continue;
        }
        visited[cur] = true;
        dist[1][cur] = min(dist[1][cur], cost);

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;

            if (!visited[next])
            {
                pq.push({ -(next_cost + cost),next });
            }
        }
    }

    pq.push({ -0,v1 });
    for (int i = 1; i <= N; i++)
    {
        visited[i] = false;
    }
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (visited[cur])
        {
            continue;
        }
        visited[cur] = true;
        dist[v1][cur] = min(dist[v1][cur], cost);
        dist[cur][v1] = min(dist[cur][v1], cost);

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;

            if (!visited[next])
            {
                pq.push({ -(next_cost + cost),next });
            }
        }
    }

    pq.push({ -0,N });
    for (int i = 1; i <= N; i++)
    {
        visited[i] = false;
    }
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (visited[cur])
        {
            continue;
        }
        visited[cur] = true;
        dist[N][cur] = min(dist[N][cur], cost);
        dist[cur][N] = min(dist[cur][N], cost);

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;

            if (!visited[next])
            {
                pq.push({ -(next_cost + cost),next });
            }
        }
    }

    int answer = min(dist[1][v1] + dist[v1][v2] + dist[v2][N], dist[1][v2] + dist[v2][v1] + dist[v1][N]);
    if (answer >= 98765432)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}