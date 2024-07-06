#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	int dp[31][31] = { 0, };
	long long int result = 0;

	for (int i = 1; i <= 30; i++)
	{
		for (int j = i; j <= 30; j++)
		{
			if (i == j)
				dp[i][j] = 1;
			else if (i == 1)
				dp[i][j] = j;
			else
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			}
		}
	}
	while (T != 0)
	{
		int N, M;
		cin >> N >> M;
		cout << dp[N][M] << '\n';
		T--;
	}
}