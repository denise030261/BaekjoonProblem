#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321;

using namespace std;

int n, m;
int map[101][101];
vector<pair<int, int>> v[101];

void dijsktra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });

    int first = start;
    while (!pq.empty())
    {
        int curDist = -pq.top().first;
        int curLoc = pq.top().second;
        pq.pop();
        
        if (curDist > map[start][curLoc])
        {
            continue;
        }

        for (int i = 0; i < v[curLoc].size(); i++)
        {
            if (map[first][v[curLoc][i].first] > curDist + v[curLoc][i].second)
            {
                map[first][v[curLoc][i].first] = curDist + v[curLoc][i].second;
                pq.push({ -map[first][v[curLoc][i].first], v[curLoc][i].first });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back(make_pair(end, cost));
    }

    for (int i = 1; i <= n; i++)
    {
        dijsktra(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 987654321 || i == j)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << map[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}