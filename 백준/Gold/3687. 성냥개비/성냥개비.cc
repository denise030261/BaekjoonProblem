#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    string min_dp[101];
    string max_dp[101];
    cin >> T;

    max_dp[3] = "7";
    max_dp[2] = "1";

    min_dp[2] = "1";
    min_dp[3] = "7";
    min_dp[4] = "4";
    min_dp[5] = "2";
    min_dp[6] = "6";
    min_dp[7] = "8";
    for (int i = 4; i <= 100; i++)
    {
        max_dp[i] = max_dp[i - 2] + max_dp[2];

        if (i > 7)
        {
            long long int num = LLONG_MAX;
            for (int j = 2; j <= 7; j++)
            {
                long long int change = LLONG_MAX;

                if (i - j != 1)
                {
                    change = stoll(min_dp[i - j] + min_dp[j]);
                    long long int temp = stoll(min_dp[j] + min_dp[i - j]);
                    change = min(change, temp);
                }

                if (i - j == 6)
                {
                    change = stoll('6' + min_dp[j]);
                    long long int temp = stoll(min_dp[j] + '6');
                    temp = min(temp, stoll(min_dp[j] + '0'));
                    change = min(change, temp);
                }
                else if (j == 6)
                {
                    change = stoll(min_dp[i - j] + '6');
                    change = min(change, stoll(min_dp[i - j] + '0'));
                    long long int temp = stoll('6' + min_dp[i - j]);
                    change = min(change, temp);
                }

                num = min(num, change);
            }

            min_dp[i] = to_string(num);
        }
    }

    while (T != 0)
    {
        int n;
        cin >> n;
        cout << min_dp[n] << ' ' << max_dp[n] << '\n';
        T--;
    }
}