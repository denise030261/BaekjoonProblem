#include <iostream> 
#include <vector>
#include <string>

using namespace std;
char map[250][250];
bool visited[250][250] = { 0, };

int wolf = 0;
int sheep = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int R, C;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C)
        {
            if (!visited[next_x][next_y])
            {
                visited[next_x][next_y] = true;

                if (map[next_x][next_y]=='o')
                {
                    sheep++;
                }
                else if (map[next_x][next_y] == 'v')
                {
                    wolf++;
                }
                else if (map[next_x][next_y] == '#')
                {
                    continue;
                }

                dfs(next_x, next_y);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    int answer_wolf = 0, answer_sheep = 0;

    for (int i = 0; i < R; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            map[i][j] = str[j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (!visited[i][j] && map[i][j] != '#')
            {
                wolf = 0;
                sheep = 0;

                if (map[i][j] == 'o')
                {
                    sheep++;
                }
                else if (map[i][j] == 'v')
                {
                    wolf++;
                }

                visited[i][j] = true;
                dfs(i, j);

                if (!(wolf == 0 && sheep == 0))
                {
                    if (wolf >= sheep)
                    {
                        answer_wolf += wolf;
                    }
                    else
                    {
                        answer_sheep += sheep;
                    }
                }
            }
        }
    }

    cout << answer_sheep << ' ' << answer_wolf;
}