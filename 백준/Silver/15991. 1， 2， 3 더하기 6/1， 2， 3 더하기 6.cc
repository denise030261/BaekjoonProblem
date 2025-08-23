#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long dp[100001] = { 0, };
	int N;
	
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	for (int i=4; i <= 100000; i++)
	{
		if (i % 2 == 0)
		{
			if (i > 6)
				dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % 1000000009;
			else
				dp[i] = (1 + dp[i - 2] + dp[i - 4])% 1000000009;
		}
		else
		{
			if (i >= 6)
				dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6])% 1000000009;
			else
				dp[i] = (dp[i - 2] + dp[i - 4])% 1000000009;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		cout << dp[num] << '\n';
	}
}