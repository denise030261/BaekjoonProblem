#include <iostream>

int map[500][500] = { 0, };
bool visited[500][500] = { 0, };

using namespace std;

int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int drawing = 0;

void dfs(int x,int y)
{
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
		{
			if (map[next_y][next_x] == 1 && !visited[next_y][next_x])
			{
				visited[next_y][next_x] = true;
				drawing++;
				dfs(next_x, next_y);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				drawing = 1;
				visited[i][j] = true;
				dfs(j, i);
				num++;
				answer = max(answer, drawing);
			}
		}
	}

	cout << num << '\n' << answer;
}