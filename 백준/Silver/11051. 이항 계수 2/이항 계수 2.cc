#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;

	int dp[1001][1001] = { 0, };

	for (int i = 1; i <= N; i++)
	{
		dp[i][1] = i;
		dp[i][i] = 1;
		dp[i][0] = 1;
	}

	for (int i = 3; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	cout << dp[N][K];
}