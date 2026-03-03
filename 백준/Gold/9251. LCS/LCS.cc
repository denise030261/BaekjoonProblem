#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str1, str2;
    int dp[1000][1000] = { 0, };
    cin >> str1 >> str2;

    for (int i = 0; i < str1.length(); i++)
    {
        int num = 0;
        for (int j = 0; j < str2.length(); j++)
        {
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                num = max(num, dp[i - 1][j - 1]);
            }

            if (str1[i] == str2[j])
            {
                if (i == 0 || j==0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] += num + 1;
                }
            }
            else if (i != 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < str2.length(); i++)
    {
        answer = max(answer, dp[str1.length() - 1][i]);
    }
    cout << answer;
}