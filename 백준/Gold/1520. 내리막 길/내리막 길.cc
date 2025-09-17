#include <iostream>

using namespace std;

int map[501][501] = { 0, };
int dp[501][501] = { 0, }; // 0은 방문 X, 1은 방문 O, 2는 방문하면 도달하는 곳
int dx[4] = { 0, 0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int M, N;

int dfs(int x, int y)
{
	int sum = 0;
	if (x == M - 1 && y == N - 1)
	{
		return 1;
	}
	else if (dp[x][y] != -1)
	{
		return dp[x][y];
	}

	int num = map[x][y];
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N)
		{
			if (num>map[next_x][next_y])
			{
				sum += dfs(next_x, next_y);
			}
		}
	}

	return  dp[x][y] = sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = -1;
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0);
}