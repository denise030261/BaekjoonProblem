#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[9] = { 0, };
int N;

void dfs(vector<int> v)
{
	if (v.size() == N)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			v.push_back(i);
			dfs(v);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v;
	visited[0] = true;
	cin >> N;

	dfs(v);
}