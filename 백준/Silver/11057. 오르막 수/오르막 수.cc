#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    long long int dp[1001][10] = { 0, };
    long long int total[1001] = { 0, };

    cin >> N;
    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    total[1] = 10;

    for (int i = 2; i <= N; i++)
    {
        for(int j=0;j<10;j++)
        {
            if (j == 0)
            {
                dp[i][j] = total[i - 1];
            }
            else
            {
                dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1]+10007) % 10007;
            }
            total[i] += dp[i][j];
        }
        total[i] %= 10007;
    }

    cout << total[N];
}