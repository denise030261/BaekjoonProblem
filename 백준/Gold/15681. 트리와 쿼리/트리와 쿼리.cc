#include <iostream>
#include <vector>

using namespace std;

bool visited[100001] = { 0, };
vector<int> v[100001];
int nodes[100001] = { 0, };

int dfs(int parent)
{
	visited[parent] = true;

	for (int i = 0; i < v[parent].size(); i++)
	{
		if (!visited[v[parent][i]])
		{
			nodes[parent] += dfs(v[parent][i]);
		}
	}

	return nodes[parent];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 0; i < N-1; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}

	for (int i = 1; i <= N; i++)
	{
		nodes[i] = 1;
	}

	dfs(R);

	for (int i = 0; i < Q; i++)
	{
		int num;
		cin >> num;
		cout << nodes[num] << '\n';
	}
}