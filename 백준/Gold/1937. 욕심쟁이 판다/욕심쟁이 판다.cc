#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int map[500][500] = { 0, };
int dp[500][500] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
        {
            if (map[x][y] < map[next_x][next_y])
            {
                if (dp[next_x][next_y] == 1)
                {
                    dfs(next_x, next_y);
                }
                dp[x][y] = max(dp[x][y], 1 +dp[next_x][next_y]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            dp[i][j] = 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dfs(i, j);
        }
    }

    int answer = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;
}