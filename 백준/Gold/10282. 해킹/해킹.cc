#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	vector<pair<int, int>> v[10001];
	int times[10001] = { 0, };
	cin >> T;

	while (T != 0)
	{
		int n, d, c;
		cin >> n >> d >> c;
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
			times[i] = INT_MAX;
		}
		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ a,s });
		}

		priority_queue<pair<int,int>> pq;
		pq.push({ 0,c }); // 시간, 현재
		while (!pq.empty())
		{
			int current = pq.top().second;
			int time = -pq.top().first;
			times[current] = min(times[current], time);
			pq.pop();
			if (times[current] < time)
				continue;

			for (int i = 0; i < v[current].size(); i++)
			{
				if(time + v[current][i].second<times[v[current][i].first])
					pq.push({ -(time + v[current][i].second),v[current][i].first });
			}
		}

		int answerNum = 0;
		int answerTime = 0;
		for (int i = 1; i <= n; i++)
		{
			if (times[i] != INT_MAX)
			{
				answerNum++;
				answerTime = max(answerTime, times[i]);
			}
		}
		cout << answerNum << ' ' << answerTime << '\n';

		T--;
	}
}