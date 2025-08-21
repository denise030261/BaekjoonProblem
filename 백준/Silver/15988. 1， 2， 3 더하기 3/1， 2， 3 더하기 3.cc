#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	long long dp[1000001] = { 0, };
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])% 1000000009;
	}
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		cout << dp[num] << '\n';
	}
}