#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[2000] = { 0, };
bool friends[2000][2000] = { 0, };
vector<int> v[2000];
int answer = 0;

void dfs(int num, int start)
{
	if (num == 4)
	{
		answer = 1;
		return;
	}

	for (int i = 0; i < v[start].size(); i++)
	{
		if (!visited[v[start][i]] && friends[start][v[start][i]])
		{
			visited[v[start][i]] = true;
			dfs(++num, v[start][i]);
			visited[v[start][i]] = false;
			num--;
		}

		if (answer == 1)
			return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		friends[a][b] = true;
		friends[b][a] = true;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (friends[i][v[i][j]])
			{
				visited[i] = true;
				visited[v[i][j]] = true;
				dfs(1, v[i][j]);
				visited[i] = false;
				visited[v[i][j]] = false;
			}
		}
	}

	cout << answer;
}