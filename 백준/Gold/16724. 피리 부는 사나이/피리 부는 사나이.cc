#include <iostream>
#include <queue>

using namespace std;

int answer = 0;
int N, M;
char map[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };

void dfs(int x,int y)
{
	visited[x][y] = 1;
	if (map[x][y] == 'D')
	{
		if (visited[x + 1][y]==0)
		{
			dfs(x + 1, y);
		}
		if (visited[x + 1][y] == 1)
		{
			answer++;
		}
	}
	else if (map[x][y] == 'L')
	{
		if (visited[x][y-1] == 0)
		{
			dfs(x, y-1);
		}
		if (visited[x][y-1] == 1)
		{
			answer++;
		}
	}
	else if (map[x][y] == 'R')
	{
		if (visited[x][y+1] == 0)
		{
			dfs(x, y+1);
		}
		if (visited[x][y+1] == 1)
		{
			answer++;
		}
	}
	else if (map[x][y] == 'U')
	{
		if (visited[x - 1][y] == 0)
		{
			dfs(x - 1, y);
		}
		if (visited[x - 1][y] == 1)
		{
			answer++;
		}
	}

	visited[x][y] = 2;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			map[i][j] = str[j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0)
			{
				dfs(i, j);
			}
		}
	}

	cout << answer;
}