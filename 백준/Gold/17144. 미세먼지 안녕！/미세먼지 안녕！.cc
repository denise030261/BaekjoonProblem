#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int R, C, T;
int arr[50][50] = { 0, }; // -1은 공기청정기
int diff_temp[50][50] = { 0, };
int blow_temp[50][50] = { 0, };
int clock_R = -1, cclock_R = -1; // 시계, 반시계 행
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void blow(int x,int y,bool clock)
{
    blow_temp[x][y + 1] = 0;
    for (int i = 1; i < C-1; i++)
    {
        blow_temp[x][i + 1] = diff_temp[x][i];
    }

    if (clock)
    {
        for (int i = x; i < R-1; i++)
        {
            blow_temp[i + 1][C - 1] = diff_temp[i][C - 1];
        }
    }
    else
    {
        for (int i = x; i >= 1; i--)
        {
            blow_temp[i - 1][C - 1] = diff_temp[i][C - 1];
        }
    }

    if (clock)
    {
        for (int i = C - 1; i >= 1; i--)
        {
            blow_temp[R - 1][i - 1] = diff_temp[R - 1][i];
        }
    }
    else
    {
        for (int i = C - 1; i >= 1; i--)
        {
            blow_temp[0][i - 1] = diff_temp[0][i];
        }
    }

    if (clock)
    {
        for (int i = R-1; i >= x+2; i--)
        {
            blow_temp[i - 1][0] = diff_temp[i][0];
        }
    }
    else
    {
        for (int i = 0; i <= x-2; i++)
        {
            blow_temp[i + 1][0] = diff_temp[i][0];
        }
    }
}

void diffusion()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            diff_temp[i][j] = 0;

            if (arr[i][j] != -1 && arr[i][j] != 0)
            {
                q.push({ i,j });
            }
        }
    }

    diff_temp[cclock_R][0] = -1;
    diff_temp[clock_R][0] = -1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int value = arr[x][y];
        int diff_val = value / 5;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x<R && next_y >= 0 && next_y<C)
            {
                if (diff_val != 0 && diff_temp[next_x][next_y]!=-1)
                {
                    diff_temp[next_x][next_y] += diff_val;
                    value -= diff_val;
                }
            }
        }
        if (value > 0)
        {
            diff_temp[x][y] += value;
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            blow_temp[i][j] = diff_temp[i][j];
        }
    }

    blow(clock_R, 0, true);
    blow(cclock_R,0,false);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            arr[i][j] = blow_temp[i][j];
        }
    }
    arr[cclock_R][0] = -1;
    arr[clock_R][0] = -1;
} // 확산

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == -1)
            {
                if (cclock_R == -1)
                {
                    cclock_R = i;
                } // 반시계
                else 
                {
                    clock_R = i;
                } // 시계
            }
        }
    }

    for (int i = 0; i < T; i++)
    {
        diffusion();
    }

    int answer = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] != -1)
            {
                answer += arr[i][j];
            }
        }
    }
    cout << answer;
}