#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int map[501][501] = { 0, };
bool visited[501][501] = { 0, };
int answer = INT_MAX;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void swap(int& a,int &b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N;

    int warningX = INT_MAX, warningY = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
        {
            continue;
        }

        swap(x1, x2);
        swap(y1, y2);

        for (int p = x1; p <= x2; p++)
        {
            for (int q = y1; q <= y2; q++)
            {
                map[p][q] = 1;
            }
        }
    }

    cin >> M;
    int dangerX = INT_MAX, dangerY = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
        {
            continue;
        }

        swap(x1, x2);
        swap(y1, y2);

        for (int p = x1; p <= x2; p++)
        {
            for (int q = y1; q <= y2; q++)
            {
                map[p][q] = 2;
            }
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ -0,{0,0} });
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (visited[x][y])
        {
            continue;
        }
        visited[x][y] = true;

        //cout << x << ' ' << y << ' ' << cost << '\n';
        if (x == 500 && y == 500)
        {
            answer = min(answer, cost);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x >= 0 && next_x <= 500 && next_y >= 0 && next_y <= 500)
            {
                if (map[next_x][next_y] != 2 && !visited[next_x][next_y])
                {
                    if (map[next_x][next_y] == 1)
                    {
                        pq.push({ -(cost + 1),{next_x,next_y} });
                    }
                    else
                    {
                        pq.push({ -cost,{next_x,next_y} });
                    }
                }
            }
        }
    }
    
    if (answer == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << answer;
}