#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char map[51][51];
    int WaterMap[51][51];
    bool visited[51][51] = { 0, };
    int answer = INT_MAX;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int R, C;
    int targetX, targetY;
    priority_queue<pair<int, pair<int, int>>> pq;
    cin >> R >> C;

    int startX = 0, startY = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            WaterMap[i][j] = INT_MAX;

            if (map[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
            else if (map[i][j] == '*')
            {
                pq.push({ 0,{ i,j } });
                visited[i][j] = true;
                WaterMap[i][j] = 0;
            }
            else if (map[i][j] == 'D')
            {
                targetX = i;
                targetY = j;
                visited[i][j] = true;
            }
            else if (map[i][j] == 'X')
            {
                visited[i][j] = true;
            }
        }
    }

    while (!pq.empty())
    {
        int time = -pq.top().first;
        int waterX = pq.top().second.first;
        int waterY = pq.top().second.second;
        pq.pop();

        for (int j = 0; j < 4; j++)
        {
            int nextX = waterX + dx[j];
            int nextY = waterY + dy[j];

            if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C)
            {
                if (map[nextX][nextY] != 'D' && map[nextX][nextY] != 'X' && !visited[nextX][nextY])
                {
                    visited[nextX][nextY] = true;
                    pq.push({ -(time + 1),{ nextX, nextY } });
                    WaterMap[nextX][nextY] = min(time + 1, WaterMap[nextX][nextY]);
                }
            }
        }
    }

    pq.push({ 0, { startX, startY } });
    memset(visited, 0, sizeof(visited));

    while (!pq.empty())
    {
        int time = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (visited[x][y])
        {
            continue;
        }
        visited[x][y] = true;

        //cout << x << ' ' << y << ' ' << time << '\n';
        if (x == targetX && y == targetY)
        {
            answer = min(answer, time);
            visited[targetX][targetY] = false;
            continue;
        }

        for (int j = 0; j < 4; j++)
        {
            int nextX = x + dx[j];
            int nextY = y + dy[j];
            if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C)
            {
                //cout << nextX << ' ' << nextY << ' ' << WaterMap[nextX][nextY] << '\n';
                if (WaterMap[nextX][nextY] > time + 1 && map[nextX][nextY] != 'X' && !visited[nextX][nextY])
                {
                    pq.push({ -(time + 1),{ nextX, nextY } });
                }
            }
        }
    }

    if (answer == INT_MAX)
    {
        cout << "KAKTUS";
    }
    else
    {
        cout << answer;
    }

}