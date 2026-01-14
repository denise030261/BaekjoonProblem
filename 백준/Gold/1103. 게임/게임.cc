#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int N, M;
int map[51][51] = { 0, };
int visited[51][51] = { 0, }; // 0이면 방문X, 1이면 방문중, 2이면 
int cost[51][51] = { 0, };
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

int dfs(int x, int y)
{
    if (cost[x][y] != 1) 
        return cost[x][y];
    //cout << "current : " << x << ' ' << y << " sum : " << sum << '\n';
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i] * map[x][y];
        int next_y = y + dy[i] * map[x][y];

        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
        {
            if (visited[next_x][next_y] == 1)
            {
                //cout << "circle : " << next_x << ' ' << next_y << '\n';
                visited[x][y] = 2;
                cost[x][y] = -1;
                return -1;
            }
            else if(map[next_x][next_y]!=-1 && visited[next_x][next_y] == 0)
            {
                visited[next_x][next_y] = 1;
                //cout << "continue visit : " << next_x << ' ' << next_y << '\n';
                int result = dfs(next_x, next_y);
                visited[next_x][next_y] = 0;

                if (result == -1)
                {
                    //cout << "반복\n";
                    cost[x][y] = -1;
                    break;
                }
                else
                {
                    cost[x][y] = max(cost[x][y], result + 1);
                }
                //cout << "dfs result : " << continueRoute << '\n';
            }
        }
    }

    //visited[x][y] = 2;
    return cost[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            cost[i][j] = 1;
            if (str[j] == 'H')
            {
                map[i][j] = -1;
            }
            else
            {
                map[i][j] = str[j] - '0';
            }
        }
    }

    visited[0][0] = 1;
    dfs(0, 0);

    if (cost[0][0] == -1)
    {
        cout << -1;
    }
    else
    {
        cout << cost[0][0];
    }
}