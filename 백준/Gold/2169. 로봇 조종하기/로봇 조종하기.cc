#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int dp[1000][1000] = { 0, };
int map[1000][1000] = { 0, };
int N, M;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            for (int k = 0; k < 3; k++)
            {
                dp[i][j] = -INT_MAX;
            }
        }
    }

    dp[0][0] = map[0][0];
    for (int i = 1; i < M; i++)
    {
        dp[0][i] = dp[0][i - 1] + map[0][i];
    }
    for (int i = 1; i < N; i++)
    {
        int Lsum[1000] = { 0, };
        int Rsum[1000] = { 0, };
        Lsum[0] = map[i][0] + dp[i - 1][0];
        for (int j = 1; j < M; j++)
        {
            Lsum[j] = map[i][j] + max(Lsum[j - 1], dp[i - 1][j]);
        }

        Rsum[M - 1] = map[i][M - 1] + dp[i - 1][M - 1];
        for (int j = M-2; j >= 0; j--)
        {
            Rsum[j] = map[i][j] + max(Rsum[j + 1], dp[i - 1][j]);
        }

        for (int j = 0; j < M; j++)
        {
            dp[i][j] = max(Rsum[j], Lsum[j]);
        }
    }

    cout << dp[N - 1][M - 1];
}