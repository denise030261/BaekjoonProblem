#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int dp[36] = { 0, };
	int n;
	cin >> n;
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}

	cout << dp[n];
}