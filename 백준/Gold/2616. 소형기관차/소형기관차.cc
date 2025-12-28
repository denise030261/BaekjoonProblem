#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int answer = 0;
    int N, M;
    int dp[50000][3] = {0,};
    vector<int> v;
    vector<int> sums;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> M;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        if (i == 0)
        {
            for (int j = 0; j < M; j++)
            {
                sum += v[i + j];
            }
            sums.push_back(sum);
            continue;
        }

        sum = sums[i - 1];
        sum -= v[i - 1];

        if (i <= N - M)
        {
            sum += v[i + M - 1];
        }
        sums.push_back(sum);
    }

    dp[0][0] = sums[0];
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = max(dp[i - 1][0], sums[i]);
        if (i - M >= 0)
        {
            dp[i][1] = max(dp[i - 1][1], dp[i - M][0] + sums[i]);
        }
        if (i - 2 * M >= 0)
        {
            dp[i][2] = max(dp[i - 1][2], dp[i - M][1] + sums[i]);
        }
    }

    cout << dp[N - 1][2];
}