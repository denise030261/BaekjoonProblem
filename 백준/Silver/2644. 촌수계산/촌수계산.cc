#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool visited[101] = { 0, };
	vector<int> v[101];
	queue<pair<int, int>> q;
	int n;
	int x, y;
	int m;

	cin >> n;
	cin >> x >> y;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int parent, child;
		cin >> parent >> child;
		v[parent].push_back(child);
		v[child].push_back(parent);
	}

	visited[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		q.push({ v[x][i],1 });
		visited[v[x][i]] = true;
	}

	int answer = -1;
	while (!q.empty())
	{
		int connect = q.front().first;
		int cost = q.front().second;
		q.pop();

		for (int i = 0; i < v[connect].size(); i++)
		{
			if (v[connect][i] == y)
			{
				answer = cost + 1;
				break;
			}

			if (!visited[v[connect][i]])
			{
				visited[v[connect][i]] = true;
				q.push({ v[connect][i],cost + 1 });
			}
		}

		if (answer != -1)
		{
			break;
		}
	}

	cout << answer;
}