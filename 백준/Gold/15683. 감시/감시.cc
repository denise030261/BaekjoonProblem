#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
vector<pair<int, int>> cctvs; // cctv 종류, x, y
int answer = 10000;
int map[8][8] = { 0, };

void check(int x, int y, int dir)
{
	dir %= 4;
	while (1)
	{
		int next_x = x + dx[dir];
		int next_y = y + dy[dir];
		x = next_x;
		y = next_y;
		if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
		{
			return;
		}

		if (map[next_x][next_y] == 6)
			return;
		if (map[next_x][next_y] != 0)
			continue;

		map[next_x][next_y] = -1;
	}
}

void dfs(int index)
{
	if (index == cctvs.size())
	{
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
					ans++;
			}
		}
		answer = min(answer, ans);
		return;
	}

	int x = cctvs[index].first;
	int y = cctvs[index].second;
	int temp[8][8] = { 0, };

	for (int dir = 0; dir < 4; dir++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				temp[i][j] = map[i][j];
			}
		}

		if (map[x][y] == 1)
		{
			check(x, y, dir);
		}
		else if (map[x][y] == 2)
		{
			check(x, y, dir);
			check(x, y, dir + 2);
		}
		else if (map[x][y] == 3)
		{
			check(x, y, dir);
			check(x, y, dir + 1);
		}
		else if (map[x][y] == 4)
		{
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
		}
		else if (map[x][y] == 5)
		{
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			check(x, y, dir + 3);
		}

		dfs(index + 1);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map[i][j] = temp[i][j];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] != 0 && map[i][j] != 6)
			{
				cctvs.push_back({ i,j });
			}
		}
	}

	dfs(0);

	cout << answer;
}