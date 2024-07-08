#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, r;
	int t[101] = { 0, };
	int item[101] = { 0, };
	int answer = 0;
	vector<pair<int, int>> v[101];
	priority_queue<pair<int, int>> pq;

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		item[i] = t[i];
	}
	for (int i = 0; i < r; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		v[start].push_back({ end,cost });
		v[end].push_back({ start,cost });
	}

	for (int i = 1; i <= n; i++)
	{
		pq.push({ 0, i });
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			item[j] = t[j];
		}

		while (!pq.empty())
		{
			int curDist = -pq.top().first;
			int curLoc = pq.top().second;
			sum += item[curLoc];
			item[curLoc] = 0;
			pq.pop();

			for (int i = 0; i < v[curLoc].size(); i++)
			{
				if (curDist + v[curLoc][i].second <= m)
				{
					pq.push({ -(curDist + v[curLoc][i].second) ,v[curLoc][i].first });
				}
			}
		}
		answer = max(answer, sum);
	}

	cout << answer;
}