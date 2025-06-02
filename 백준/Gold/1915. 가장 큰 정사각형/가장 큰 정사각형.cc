#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	int answer = 0;
	int dp[1001][1001] = { 0, };
	int map[1001][1001];
	cin >> n >> m;

	string str;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = str[j-1] - '0';
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1)
			{
				dp[i][j] = 1;
				
				if (map[i - 1][j] == 1 && map[i][j - 1] == 1 && map[i - 1][j - 1] == 1)
				{
					dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
				}
			}

			answer = max(answer, dp[i][j]);
		}
	}
	
	cout << answer * answer;
}
