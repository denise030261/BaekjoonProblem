#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

char map[10000][500];
bool visited[10000][500]; 
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
int answer = 0;
int R, C;

bool dfs(int x, int y)
{
    bool possible = false;
    if (y == C - 1)
    {
        answer++;
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (possible)
        {
            break;
        }

        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C)
        {
            if (map[next_x][next_y] == '.' && !visited[next_x][next_y])
            {
                possible = dfs(next_x, next_y);
                map[next_x][next_y] = 'x';
            }
        }
    }

    return possible;
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        visited[i][0] = true;
        if (dfs(i, 0));
        {
            map[i][0] = 'x';
        }
        visited[i][0] = false;
    }

    cout << answer;
}