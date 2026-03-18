#include <iostream> 
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int dx[3] = { 0,-1,-1 };
    int dy[3] = { -1,-1,0 };
    int N, M;
    cin >> N >> M;
    int arr[1000][1000] = { 0, };
    int dp[1000][1000] = { 0, };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];

            for (int k = 0; k < 3; k++)
            {
                int prev_x = i + dx[k];
                int prev_y = j + dy[k];

                if (prev_x >= 0 && prev_y >= 0)
                {
                    dp[i][j] = max(dp[i][j], dp[prev_x][prev_y] + arr[i][j]);
                }
            }
        }
    }

    cout << dp[N - 1][M - 1];
}