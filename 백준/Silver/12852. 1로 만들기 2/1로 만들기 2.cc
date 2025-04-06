#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    vector<pair<int, int>> dp;
    cin >> N;

    dp.push_back({ 0,1 });
    dp.push_back({ 0,1 });
    for (int i = 2; i <= 1000000; i++)
    {
        dp.push_back({INT_MAX,1});
    } // Init

    for (int i = 1; i < 1000000; i++)
    {
        if (dp[i + 1].first > dp[i].first + 1)
        {
            dp[i + 1].first = dp[i].first + 1;
            dp[i + 1].second = i;
        }
        if (i*2<= 1000000)
        {
            if (dp[i * 2].first > dp[i].first + 1)
            {
                dp[i * 2].first = dp[i].first + 1;
                dp[i * 2].second = i;
            }
        }
        if (i * 3 <= 1000000)
        {
            if (dp[i * 3].first > dp[i].first + 1)
            {
                dp[i * 3].first = dp[i].first + 1;
                dp[i * 3].second = i;
            }
        }
    }

    cout << dp[N].first << '\n';
    while (N != 1)
    {
        cout << N << ' ';
        N = dp[N].second;
    }
    cout << 1;
}