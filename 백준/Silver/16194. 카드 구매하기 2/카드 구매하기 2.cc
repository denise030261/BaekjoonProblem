#include <iostream>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int arr[1001] = { 0, };
	int dp[1001] = { 0, };
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		dp[i] = INT_MAX;
		cin >> arr[i];
		for (int j = 0; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + arr[j]);
		}
	}
	cout << dp[N];
}