#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int answer = 0;
int far = 0;
bool visited[100001] = { 0, };
vector<pair<int, int>> edges[100001];

void dfs(int node,int sum)
{
	if (sum > answer)
	{
		far = node;
		answer = sum;
	}

	for (int i = 0; i < edges[node].size(); i++)
	{
		if (!visited[edges[node][i].first])
		{
			visited[edges[node][i].first] = true;
			dfs(edges[node][i].first, sum + edges[node][i].second);
		}
	}
}


int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int V;
	cin >> V;

	for (int i = 0; i < V; i++)
	{
		int node;
		int next, edge;
		cin >> node;

		cin >> next;
		if (next == -1)
		{
			continue;
		}
		else
		{
			while (next != -1)
			{
				cin >> edge;
				edges[node].push_back({ next,edge });
				cin >> next;
			}
		}
	}

	visited[1] = true;
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));

	answer = 0;
	visited[far] = true;
	dfs(far, 0);

	cout << answer;
}
