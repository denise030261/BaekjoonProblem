#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	int dp[31] = { 0, };
	if (N % 2 == 1)
	{
		cout << 0;
		return 0;
	}

	dp[2] = 3;
	for (int i = 4; i <= 30; i += 2)
	{
		int sum = 2 + dp[i - 2] * dp[2];
		for (int j = 4; j < i; j+=2)
		{
			sum += dp[i - j] * 2;
		}
		dp[i] = sum;
	}

	cout << dp[N];
}