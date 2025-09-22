#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[51][51] = { 0, };
bool visited[51][51] = { 0, };
int N, M;

void dfs(int x,int y,char c)
{
	if (c == '-')
	{
		y++;
	}
	else
	{
		x++;
	}

	if (x >= 0 && x < N && y >= 0 && y < M)
	{
		if (!visited[x][y] && map[x][y] == c)
		{
			visited[x][y] = true;
			dfs(x, y, c);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j];
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = true;
				dfs(i, j, map[i][j]);
				answer++;
			}
		}
	}
	cout << answer;
}