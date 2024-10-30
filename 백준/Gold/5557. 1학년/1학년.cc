#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	long long int dp[101][21] = { 0, };
	int arr[100] = { 0, };
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dp[0][arr[0]] = 1;
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i][j])
			{
				if (j + arr[i + 1] <= 20)
				{
					dp[i + 1][j + arr[i + 1]] += dp[i][j];
				}
				if (j - arr[i + 1] >= 0)
				{
					dp[i + 1][j - arr[i + 1]] += dp[i][j];
				}
			}
		}
	}

	cout << dp[N - 2][arr[N - 1]];
}