#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int dp[100001] = { 0, };
	long long int N, K;
	cin >> N >> K;

	dp[0] = 0;
	cin >> dp[1];
	for (int i = 2; i <= N; i++)
	{
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	long long int answer = -987654321;
	for (int i = 1; i <= N; i++)
	{
		if(i-K>=0)
			answer = max(answer, dp[i]-dp[i-K]);
	}

	cout << answer;
}