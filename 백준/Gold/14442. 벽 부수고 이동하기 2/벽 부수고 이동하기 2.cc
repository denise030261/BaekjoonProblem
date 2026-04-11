#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int arr[1000][1000] = { 0, };
int dist[1000][1000][11] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    queue < pair<pair<int, int>, pair<int, int>>> pq;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    pq.push({ {0,0},{0,0} });
    int answer = -1;
    while (!pq.empty())
    {
        int cost = pq.front().first.first;
        int broke = pq.front().first.second;
        int x = pq.front().second.first;
        int y = pq.front().second.second;
        pq.pop();

        if (x == N - 1 && y == M - 1)
        {
            answer = cost + 1;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
            {
                if (arr[next_x][next_y] == 0 &&
                    (dist[next_x][next_y][broke] == 0 || dist[next_x][next_y][broke] > cost + 1))
                {
                    dist[next_x][next_y][broke] = cost + 1;
                    pq.push({ {(cost + 1),broke},{next_x,next_y} });
                }
                else if (arr[next_x][next_y] == 1 && broke + 1 <= K)
                {
                    if (dist[next_x][next_y][broke + 1] == 0 || dist[next_x][next_y][broke + 1] > cost + 1)
                    {
                        dist[next_x][next_y][broke + 1] = cost + 1;
                        pq.push({ {(cost + 1),broke + 1},{next_x,next_y} });
                    }
                }
            }
        }
    }

    cout << answer;
}