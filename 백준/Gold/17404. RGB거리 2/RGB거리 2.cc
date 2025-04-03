#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int RGB[1001][3] = { 0, };
    int dp[1001][3] = { 0, };

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }

    int answer = INT_MAX;
    for (int firstColor = 0; firstColor <= 2; firstColor++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (j == firstColor)
                dp[1][j] = RGB[1][j];  
            else
                dp[1][j] = 1e9;  
        }

        for (int j = 2; j <= N; j++)
        {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + RGB[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + RGB[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + RGB[j][2];
        }

        for (int lastColor = 0; lastColor <= 2; lastColor++)
        {
            if (lastColor == firstColor)
                continue;
            answer = min(answer, dp[N][lastColor]);
        }
    }

    cout << answer;
}
