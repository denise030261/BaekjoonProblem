#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, H;
	int dp[51][1001] = { 0, };
    vector <int> v[51];
	cin >> N >> M >> H;
	cin.ignore(1);

	for (int i = 1; i <= N; i++) 
	{
		string temp;
		getline(cin, temp, '\n');

		for (int j = 0; j < temp.size(); j++)
			if (temp[j] == ' ' || j == 0)
			{
				v[i].push_back(stoi(&temp[j]));
			}
	}

	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= H; j++)
		{
			for (int k = 0; k < v[i].size(); k++)
			{
				if (j >= v[i][k])
				{
					dp[i][j] += dp[i - 1][j - v[i][k]];
					dp[i][j] %= 10007;
				}
			}

			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= 10007;
		}
	}

	cout << dp[N][H];
}