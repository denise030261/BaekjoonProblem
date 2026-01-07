#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

int N;
int arr[17][17] = { 0, };
int dp[17][(1 << 17) - 1] = { 0, };

int dfs(int current, int visited)
{
    if (visited == (1 << N) - 1) 
    {
        if (arr[current][1] == 0)
            return 17000000;

        return arr[current][1]; 
    } // 모두 다 방문 했을 때

    if (dp[current][visited] != -1) 
        return dp[current][visited]; // 이미 계산을 했을 때

    dp[current][visited] = 17000000;
    for (int i = 1; i <= N; i++)
    {
        if ((visited & (1 << (i-1))) == 0 && arr[current][i] != 0)
        {
            int temp = dfs(i, visited | (1 << (i - 1)));
            dp[current][visited] = min(dp[current][visited], arr[current][i] + temp);
        }
    }

    return dp[current][visited];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int result = dfs(1, 1);
    if (result == 17000000)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }
}