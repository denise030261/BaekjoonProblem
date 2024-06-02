#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int sum = 0;
	cin >> N;

	int dp[100001] = { 0, };
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] * 2 + dp[i-2]) % 9901;
	}

	cout << dp[N];
}
