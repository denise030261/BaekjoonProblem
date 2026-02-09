#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    int dp[101][100001] = { 0, };
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        int W, V;
        cin >> W >> V;
        for (int j = 1; j <= K; j++)
        {
            if (j - W >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    /*int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            cout << dp[i][j] << ' ';
            answer = max(dp[i][j], answer);
        }

        cout << '\n';
    }

    cout << answer;*/
    cout << dp[N][K];
}