#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int dp[91] = { 0, };
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];
}