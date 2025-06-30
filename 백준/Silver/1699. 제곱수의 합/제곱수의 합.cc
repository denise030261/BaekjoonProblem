#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int dp[100001] = { 0, };
	vector<int> v;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	v.push_back(1);
	for (int i = 4; i <= N; i++)
	{
		if (pow((int)sqrt(i),2)==i)
		{
			dp[i] = 1;
			v.push_back(i);
		}
		else
		{
			dp[i] = 987654321;
			for (int j = v.size() - 1; j >= 0; j--)
			{
				if (i >= v[j])
				{
					dp[i] = min(1 + dp[i - v[j]],dp[i]);
				}
			}
		}
	}

	cout << dp[N];
}