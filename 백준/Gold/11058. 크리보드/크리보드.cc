#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	long long int dp[101] = { 0, };

	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = i;
		for (int j = 3; j <= i - 1; j++)
		{
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}

	cout << dp[N];
}