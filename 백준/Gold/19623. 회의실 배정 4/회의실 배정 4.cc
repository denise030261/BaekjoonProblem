#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.first < b.second.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<pair<int, pair<int, int>>>v;
	int dp[100000] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start,end,num;
		cin >> start >> end >> num;
		v.push_back({ start,{end,num} });
	}
	sort(v.begin(), v.end(),compare);

	dp[0] = v[0].second.second;
	for (int i = 1; i < v.size(); i++)
	{
		int start = v[i].first;
		int end = v[i].second.first;
		int num = v[i].second.second;

		int sta = 0;
		int fin = i - 1;
		int optimal = -1;
		while (sta <= fin)
		{
			int mid = (sta + fin) / 2;
			if (start >= v[mid].second.first)
			{
				optimal = mid;
				sta = mid + 1;
			}
			else
			{
				fin = mid - 1;
			}
		}

		if (optimal == -1)
		{
			dp[i] = max(dp[i - 1], num);
		}
		else
		{
			dp[i] = max(dp[i - 1], dp[optimal] + num);
		}
	}

	cout << dp[N - 1];
}