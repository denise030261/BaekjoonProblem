#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int M, N;
int map[1000][1000] = { 0, };
int answer[1000][1000] = { 0, };
int areas[1000][1000] = { 0, };
int areaLabel[1000][1000] = { 0, };
bool visited[1000][1000] = { 0, };
vector<pair<int, int>> v;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int dfs(int x,int y,int sum)
{
    int area = sum;
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
        {
            if (!visited[next_x][next_y])
            {
                if (map[next_x][next_y] == 0)
                {
                    visited[next_x][next_y] = true;
                    v.push_back({ next_x,next_y });
                    area = dfs(next_x, next_y, area + 1);
                }
            }
        }
    }

    return area;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector<pair<int, int>> zero;
    vector<pair<int, int>> one;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = str[j] - '0';
            if (map[i][j] == 1)
            {
                one.push_back({ i,j });
            }
            else
            {
                zero.push_back({ i,j });
            }
        }
    }

    int index = 1;
    for (int i = 0; i < zero.size(); i++)
    {
        int x = zero[i].first;
        int y = zero[i].second;

        if (!visited[x][y])
        {
            v.clear();
            visited[x][y] = true;
            int total =dfs(x, y, 1);

            areas[x][y] = total;
            areaLabel[x][y] = index;
            for (int j = 0; j < v.size(); j++)
            {
                areas[v[j].first][v[j].second] = total;
                areaLabel[v[j].first][v[j].second] = index;
            }

            index++;
        }
    }

    for (int i = 0; i < one.size(); i++)
    {
        int x = one[i].first;
        int y = one[i].second;
        answer[x][y]++;

        set<int> s;
        for (int j = 0; j < 4; j++)
        {
            int next_x = x + dx[j];
            int next_y = y + dy[j];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
            {
                if (s.find(areaLabel[next_x][next_y]) == s.end())
                {
                    answer[x][y] = (answer[x][y] + areas[next_x][next_y]) % 10;
                    s.insert(areaLabel[next_x][next_y]);
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << answer[i][j];
        }
        cout << '\n';
    }
}