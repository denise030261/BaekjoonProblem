#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int answer = 0;
    int T[1500001] = { 0, };
    int P[1500001] = { 0, };
    int dp[1500001] = { 0, };
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N+1; i++)
    {
        dp[i] = max(dp[i - 1], dp[i]);

        if (i + T[i] <= N+1)
        {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
    }

    cout << dp[N + 1] << '\n';
}