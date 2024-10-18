#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<pair<int, int>> v[100001];
	priority_queue<pair<int, int>>pq;
	bool visited[100001] = { 0, };
	pq.push({ 0,1 });

	cin >> N >> M;
	int start, end, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> cost;
		v[start].push_back({ end,cost });
		v[end].push_back({ start,cost });
	}

	int result = 0;
	int broken = 0;
	while (!pq.empty())
	{
		int target = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (visited[target])
		{
			continue;
		}
		else
		{
			visited[target] = true;
			broken = max(cost, broken);
			result += cost;
		}

		for (int i = 0; i < v[target].size(); i++)
		{
			if (!visited[v[target][i].first])
			{
				pq.push({ -v[target][i].second,v[target][i].first });
			}
		}
	}

	cout << result-broken;
}