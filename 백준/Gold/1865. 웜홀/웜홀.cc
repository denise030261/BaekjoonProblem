#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

vector<pair<int,pair<int, int>>> edges; // 다음 위치 및 비용
int dist[501] = { 0, };
int TC, N, M, W;

bool bellmanFord()
{
	dist[1] = 0;
	
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int from = edges[j].first;
			int to = edges[j].second.first;
			int cost = edges[j].second.second;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
			}
		}
	}
	
	for (int i = 0; i < edges.size(); i++)
	{
		int from = edges[i].first;
		int to = edges[i].second.first;
		int cost = edges[i].second.second;

		if (dist[to] > dist[from] + cost)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> TC;

	while (TC != 0)
	{
		edges.clear();
		for (int i = 1; i <= 500; i++)
		{
			dist[i] = 1e9;
		}

		cin >> N >> M >> W;
		for (int i = 0; i < M; i++)
		{
			int S, E, T;
			cin >> S >> E >> T;
			edges.push_back({ S,{E,T} });
			edges.push_back({ E,{S,T} });
		}
		for (int i = 0; i < W; i++)
		{
			int S, E, T;
			cin >> S >> E >> T;
			edges.push_back({ S,{ E,-T } });
		}

		if (bellmanFord())
			cout << "YES\n";
		else
			cout << "NO\n";

		TC--;
	}
}