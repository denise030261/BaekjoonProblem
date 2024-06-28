#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K, W, V;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W >> V;

		for (int j = 1; j <= K; j++)
		{
			if (j >= W)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
}