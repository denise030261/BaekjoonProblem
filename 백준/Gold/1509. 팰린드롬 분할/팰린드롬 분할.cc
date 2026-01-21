#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
    int N = str.length();
    vector<vector<bool>> p(N, vector<bool>(N, false));
    vector<int> dp(N, 10000);

    for (int i = 0; i < N; i++) 
    {
        p[i][i] = true;
    }
    for (int i = 0; i < N - 1; i++) 
    {
        if (str[i] ==str[i + 1]) 
        {
            p[i][i + 1] = true;
        }
    }
    for (int i = 2; i < N; i++) 
    {
        for (int j = 0; j + i < N; j++) 
        {
            if (p[j + 1][j + i - 1] && str[j] == str[j + i]) 
            {
                p[j][j + i] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        if (p[0][i])
        {
            dp[i] = 1;
        }
        else 
        {
            for (int k = 0; k < i; k++) 
            {
                if (p[i - k][i]) 
                {
                    dp[i] = min(dp[i], dp[i - k - 1] + 1);
                }
            }
        }
    }

    cout << dp[N - 1];

}