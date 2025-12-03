#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
vector<pair<int,int>> v[100001];
int dist[100001] = { 0, };
bool visited[100001] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    int startN, endN;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INT_MAX;
    }
    for (int i = 0; i < M; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({ end,cost });
    }
    cin >> startN >> endN;

    int answer = INT_MAX;
    priority_queue<pair<int, int>> pq;
    pq.push({ -0,startN });

    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (node == endN)
        {
            answer = min(answer, cost);
            break;
        }

        for (int i = 0; i < v[node].size(); i++)
        {
            int next_node = v[node][i].first;
            int next_cost = v[node][i].second + cost;
            if (dist[next_node]> next_cost)
            {
                dist[next_node] = next_cost;
                pq.push({ -next_cost, next_node });
            }
        }
    }
    cout << answer;
}