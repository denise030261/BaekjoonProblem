#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#define INF 987654321

using namespace std;

int N;
double dp[17][140000] = { 0, };
double map[17][17] = { 0, };
pair<int, int> node[17];

double dfs(int current, int visited)
{
    if (dp[current][visited] != INF)
    {
        return dp[current][visited];
    }

    if (visited == (1 << N) - 1)
    {
        if (map[current][0] == INF)
        {
            return INF;
        }

        return map[current][0];
    }

    for (int i = 0; i < N; i++)
    {
        if (map[current][i] == INF || ((visited & (1 << i))) == (1 << i))
        {
            continue;
        }
        
        dp[current][visited] = min(dp[current][visited], map[current][i] + dfs(i, visited | 1 << i));
    }

    return dp[current][visited];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        node[i].first = x;
        node[i].second = y;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            map[i][j] = INF;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            dp[i][j] = INF;
        }
    } // init

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            map[i][j] = sqrt(pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2));
            map[j][i] = map[i][j];
        }
    } // make route

    cout << fixed; cout.precision(6);
    cout << dfs(0, 1);
}