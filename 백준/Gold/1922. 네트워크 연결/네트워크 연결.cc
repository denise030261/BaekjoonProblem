#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int  N, M;
	int result = 0;
	bool visited[1001] = { 0, };
	vector<pair<int, int>> v[1001];
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });

	cin >> N >> M;
	for (int i = 0; i < M; i++)
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