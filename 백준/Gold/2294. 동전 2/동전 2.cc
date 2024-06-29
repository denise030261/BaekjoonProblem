#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    int dp[10001] = { 0, };

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    for (int i = 1; i <= k; i++)
    {
        dp[i] = 999999;
        for (int j = 0; j < n; j++)
        {
            if (i - coin[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    if (dp[k] == 999999)
    {
        cout << -1;
        return 0;
    }
    cout << dp[k];
}