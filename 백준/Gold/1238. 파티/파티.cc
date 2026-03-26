#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321;

using namespace std;

int N, M, X;
vector<pair<int, int>> road[1001];
int cost[1001][1001] = { 0, };
priority_queue<pair<int, int>> pq;

void bfs(int start)
{
    pq.push({ -0,start });

    while (!pq.empty())
    {
        int time = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < road[cur].size(); i++)
        {
            int next_node = road[cur][i].first;
            int next_time = road[cur][i].second;
            if (cost[start][next_node] > time + next_time)
            {
                cost[start][next_node] = time + next_time;
                pq.push({ -(time + next_time),next_node });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int start, end, time;
        cin >> start >> end >> time;
        road[start].push_back({ end,time });
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cost[i][j] = INF;
        }
        cost[i][i] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        bfs(i);
    }

    /*for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }*/
    int answer = -1;
    for (int i = 1; i <= N; i++)
    {
        if (i == X)
        {
            continue;
        }

        int sum = 0;
        sum += cost[i][X];
        sum += cost[X][i];
        answer = max(sum, answer);
    }
    cout << answer;
}