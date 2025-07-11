#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	int dp[501][501] = { 0, };
	int sum[501] = { 0, };
	cin >> T;

	while (T != 0)
	{
		int K;
		cin >> K;

		for (int i = 1; i <= K; i++)
		{
			int num;
			cin >> num;
			sum[i] = sum[i - 1] + num;
		}

		for (int i = 1; i < K; i++) 
		{ 
			for (int x = 1; x <= K - i; x++) 
			{ 
				int y = x + i;
				dp[x][y] = 987654321; 

				for (int mid = x; mid < y; mid++)
				{ 
					dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
				}
			}
		}
		cout << dp[1][K] << "\n";

		T--;
	}
}