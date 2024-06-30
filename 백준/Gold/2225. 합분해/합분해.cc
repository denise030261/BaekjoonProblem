#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	int dp[201][201] = { 0, };
	cin >> N >> K;
	
	for (int i = 1; i <= K; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j == 1)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
			}
		}
	}

	cout << dp[N][K];
}