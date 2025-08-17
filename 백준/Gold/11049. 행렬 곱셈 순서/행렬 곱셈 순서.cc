#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int dp[502][502] = { 0, };
	int matrix[502][2] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int r,c;
		cin >> r>>c;
		matrix[i+1][0] = r;
		matrix[i+1][1] = c;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; i+j <= N; j++)
		{
			dp[j][i + j] = INT_MAX;
			for (int k = j; k <= i+j; k++)
			{
				dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k + 1][i+j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
			}
		}
	}

	cout << dp[1][N];
}