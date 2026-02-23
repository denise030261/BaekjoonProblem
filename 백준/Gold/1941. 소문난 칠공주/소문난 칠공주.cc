#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

char map[5][5];
bool check[5][5] = { 0, };
bool visited[5][5] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;
vector<int> v;

int sum()
{
    int total = 0;
    queue<pair<int, int>> q;
    q.push({ v[0] / 5, v[0] % 5 });
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (visited[x][y])
        {
            continue;
        }
        visited[x][y] = true;
        total++;

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5)
            {
                if (!visited[next_x][next_y]
                    && check[next_x][next_y]) // 길이 이어져있는지 판단
                {
                    q.push({ next_x,next_y });
                }
            }
        }
    }
    return total;
}

void dfs(int length, int index)
{
    if (length == 7)
    {
        int S = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i] / 5;
            int y = v[i] % 5;
            if (map[x][y]=='S')
            {
                S++;
            }
            check[x][y] = true;
        } // S가 몇 개인지 판단

        if (S >= 4)
        {
            if (sum() == 7)
            {
                answer++;
            }
        }


        for (int i = 0; i < v.size(); i++)
        {
             int x = v[i] / 5;
             int y = v[i] % 5;
             check[x][y] = false;
             visited[x][y] = false;
        }

        return;
    }

    for (int i = index; i < 25; i++)
    {
        v.push_back(i);
        dfs(length + 1, i + 1);
        v.pop_back();
    } // 5x5->index 형태로
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0, 0);

    cout << answer;
}