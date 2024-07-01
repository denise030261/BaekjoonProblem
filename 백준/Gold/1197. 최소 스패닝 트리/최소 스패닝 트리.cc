#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int V, E;
	int result = 0;
	bool visited[10001] = { 0, };
	vector<pair<int, int>> v[10001];
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });

	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
		v[B].push_back({ A,C });
	}

	while (!pq.empty())
	{
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (visited[current])
			continue;

		result += cost;
		visited[current] = true;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].first;
			int next_cost = v[current][i].second;
			pq.push({ -next_cost,next });
		}
	}

	cout << result;
}