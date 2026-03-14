#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int map[15][15] = { 0, };
int N, M, D;
int answer = 0;
int enemy = 0;

void simulation(vector<int> v)
{
    int temp[15][15];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            temp[i][j] = map[i][j];
        }
    }

    vector< pair<pair<int, int>, int>> archers;
    archers.push_back({ {N,v[0]},INT_MAX }); // N,v[0]
    archers.push_back({ {N,v[1]},INT_MAX }); // N,v[1]
    archers.push_back({ {N,v[2]},INT_MAX }); // N,v[2]
    int sum = 0;
    int T = N;
    //cout << "New\n";
    while (T != 0)
    {
        for (int k = 0; k < 3; k++)
        {
            archers[k] = { {N,v[k]},INT_MAX };
        }

        // 적 쏘기
        for (int i = 0; i < M; i++)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (temp[j][i] == 0)
                    continue;

                for (int k = 0; k < 3; k++)
                {
                    int cost = archers[k].second;

                    int dist = abs(N - j) + abs(v[k] - i);
                    if (dist <= D && dist < cost)
                    {
                        archers[k] = { {j,i},dist };
                    }
                }
            }
        }

        // 궁수 쏘기
        for (int k = 0; k < 3; k++)
        {
            int x = archers[k].first.first;
            int y = archers[k].first.second;
            int cost = archers[k].second;

            if (cost == INT_MAX)
                continue;

            if (temp[x][y] == 1)
            {
                temp[x][y] = 0;
                sum++;
            }
        }

        // 적 내려가기
        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = 0; j < M; j++)
            {
                temp[i][j] = temp[i - 1][j];
            }
        }
        for (int j = 0; j < M; j++)
        {
            temp[0][j] = 0;
        }

        /*for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << temp[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << "=========================================\n";*/

        T--;
    }

    answer = max(answer, sum);
}

void dfs(vector<int> v, int index)
{
    if (v.size() == 3)
    {
        simulation(v);
        return;
    }

    for (int i = index; i < M; i++)
    {
        v.push_back(i);
        dfs(v, i + 1);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> D;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                enemy++;
            }
        }
    }

    vector<int> v;
    dfs(v, 0);

    cout << answer;
}