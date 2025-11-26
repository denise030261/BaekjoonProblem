#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int N;
int map[100][100] = { 0, };
bool visited[100][100] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = INT_MAX;
vector<pair<int, int>> v[10001];

void search(int x, int y, int num)
{
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
        {
            if (!visited[next_x][next_y] && map[next_x][next_y]==1)
            {
                visited[next_x][next_y] = true;
                map[next_x][next_y] = num;
                v[num].push_back({ next_x,next_y });
                search(next_x, next_y, num);
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
        }
    }

    int num = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && map[i][j]==1)
            {
                visited[i][j] = true;
                map[i][j] = num;
                v[num].push_back({ i,j });
                search(i, j, num);
                num++;
            }
        }
    }

    for (int i = 0; i < num-1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            for (int p = 0; p < v[i].size(); p++)
            {
                for (int q = 0; q < v[j].size(); q++)
                {
                    answer = min(answer, abs(v[i][p].first - v[j][q].first) + abs(v[i][p].second - v[j][q].second));
                }
            }
        }
    }

    cout << answer - 1;
}