#include <iostream>

using namespace std;

int N, M;
int tree[1001][1001] = { 0, };
int visited[1001] = { 0, };
int answer = 0;

void dfs(int start, int target, int sum)
{
	for (int i = 1; i <= N; i++)
	{
		if (target == i && tree[start][i] != 0 && !visited[i])
		{
			visited[i] = true;
			sum += tree[start][i];
			answer = sum;
			return;
		}
		else if(tree[start][i] != 0 && !visited[i])
		{
			visited[i] = true;
			sum += tree[start][i];
			dfs(i, target,sum);
			sum -= tree[start][i];
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	int first, end, cost;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> first >> end >> cost;
		tree[first][end] = cost;
		tree[end][first] = cost;
	}

	int start, target;
	for (int i = 0; i < M; i++)
	{
		fill(visited, visited + 1001, 0);
		answer = 0;
		cin >> start >> target;
		visited[start] = true;
		dfs(start, target,0);
		cout << answer << '\n';
	}
}