#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int visited[100001];
vector<pair<int, int> >node[100001];
int answer = -1, maxnode = 0;

void dfs(int current, int dist) 
{
	visited[current] = 1;
	if (answer < dist) 
	{
		answer = dist;
		maxnode = current;
	}
	for (int i = 0; i < node[current].size(); i++) 
	{
		if (visited[node[current][i].first] == 1)
			continue;
		dfs(node[current][i].first, dist + node[current][i].second);
	}
}

int main() 
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int V;
		cin >> V;

		while (1)
		{
			int edge, cost;
			cin >> edge;
			if (edge == -1)
				break;
			else
			{
				cin >> cost;
				node[V].push_back({ edge,cost });
			}
		}
	}
	dfs(1, 0);
	fill(visited, visited + 100001, 0);
	answer = -1;
	dfs(maxnode, 0);
	cout << answer << endl;
}