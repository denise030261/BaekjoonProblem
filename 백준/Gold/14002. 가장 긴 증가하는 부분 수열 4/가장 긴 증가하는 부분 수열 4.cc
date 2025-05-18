#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int dp[1000] = { 0, };
	int num[1000] = { 0, };
	vector<int> answer;
	int len = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];

		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (num[j] < num[i] && dp[j]>=dp[i])
				dp[i] = dp[j] + 1;
		}

		len = max(dp[i], len);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (len == dp[i])
		{
			answer.push_back(num[i]);
			len--;
		}
	}

	cout << answer.size() << '\n';
	for (int i = answer.size() - 1; i >= 0;i--)
	{
		cout << answer[i] << ' ';
	}
}