#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = INT_MAX;
	int N, M;
	int dp[10001] = { 0, };
	vector<pair<int, int>> v;
	vector<int> ms;
	vector<int> cs;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int m;
		cin >> m;
		ms.push_back(m);
	}
	for (int i = 0; i < N; i++)
	{
		int c;
		cin >> c;
		cs.push_back(c);
	}
	for (int i = 0; i < N; i++)
	{
		v.push_back({ ms[i],cs[i] });
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 10000; j >= v[i].second; j--)
		{
			dp[j] = max(dp[j], dp[j - v[i].second] + v[i].first);
			if (dp[j] >= M)
			{
				answer = min(answer, j);
			}
		}
	}

	cout << answer;
}