#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, s, t;
	vector<pair<long int, long int>> v[5001];
	bool visited[5001] = { 0, };
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cin >> s >> t;

	priority_queue<pair<int, int>> pq;
	pq.push({ -0,s });
	int answer = INT_MAX;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int num = pq.top().second;
		visited[num] = true;
		pq.pop();

		if (num == t)
		{
			answer = min(answer, cost);
			break;
		}

		for (int i = 0; i < v[num].size(); i++)
		{
			int connect = v[num][i].first;
			int plus = v[num][i].second;

			if (!visited[connect])
			{
				pq.push({ -(cost + plus),connect });
			}
		}
	}

	cout << answer;
}