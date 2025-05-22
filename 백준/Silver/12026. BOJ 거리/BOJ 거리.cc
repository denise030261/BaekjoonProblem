#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int N;
	int dp[1000];
	for (int i = 0; i < 1000; i++)
		dp[i] = INT_MAX;

	cin >> N;
	cin >> str;
	
	dp[0] = 0;
	for (int i = 1; i < str.length(); i++)
	{
		int k = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			k++;
			if ((str[j] == 'B' && str[i] == 'O' || str[j] == 'O' && str[i] == 'J' || str[j] == 'J' && str[i] == 'B')
				&& dp[j]!=INT_MAX)
			{
				dp[i] = min(dp[i], dp[j] + k * k);
			}
		}
	}

	if (dp[N - 1] == INT_MAX)
		cout << -1;
	else
		cout << dp[N - 1];
}