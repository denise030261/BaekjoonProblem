#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, W;
	vector<int> apple;
	int dp[1001][31][3] = { 0, };
	cin >> T >> W;

	apple.push_back(1);
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		apple.push_back(num);
	}

	for (int i = 1; i <= T; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (apple[i] == 1)
			{
				dp[i][j][1] = max(dp[i - 1][j][1] + 1, dp[i][j][1]);
				if(j+1<=W)
					dp[i][j + 1][1] = max(dp[i - 1][j][2] + 1, dp[i][j + 1][1]);

				dp[i][j][2] = dp[i - 1][j][2];
			}
			else
			{
				if(i!=1)
					dp[i][j][2] = max(dp[i - 1][j][2] + 1, dp[i][j][2]);

				if (j + 1 <= W)
					dp[i][j + 1][2] = max(dp[i - 1][j][1] + 1, dp[i][j + 1][2]);

				dp[i][j][1] = dp[i - 1][j][1];
			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= W; i++)
	{
		answer = max(answer, max(dp[T][i][1], dp[T][i][2]));
	}
	cout << answer;
}