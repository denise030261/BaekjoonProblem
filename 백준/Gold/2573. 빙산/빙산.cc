#include <iostream>
#include <vector>

using namespace std;

int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[300][300] = { 0, };
int changeMap[300][300] = { 0, };
bool visited[300][300] = { 0, };
vector<pair<int, int>> dots;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
		{
			if (!visited[next_x][next_y] && map[next_x][next_y]!=0)
			{
				visited[next_x][next_y] = true;
				dots.push_back({ next_x,next_y });
				dfs(next_x, next_y);
			}
		}
	}
}

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = changeMap[i][j];
			visited[i][j] = false;
		}
	}

	dots.clear();
}

void melting()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			changeMap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < dots.size(); i++)
	{
		int x = dots[i].first;
		int y = dots[i].second;
		for (int k = 0; k < 4; k++)
		{
			int next_x = x + dx[k];
			int next_y = y + dy[k];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
			{
				if (map[next_x][next_y] == 0)
				{
					changeMap[x][y] = (changeMap[x][y] - 1 >= 0 ? changeMap[x][y] - 1 : 0);
				}
			}
		}
	}

	init();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	int answer = 0;
	while (1)
	{
		// 한 덩어리인지 파악
		int loaf = 0;
		bool exist = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] != 0 && !visited[i][j])
				{
					dots.push_back({ i,j });
					exist = true;
					loaf++;
					visited[i][j] = true;
					dfs(i, j);
				}
			}
		}

		if (loaf >= 2)
		{
			cout << answer;
			break;
		}
		else if (!exist)
		{
			cout << 0;
			break;
		}

		// 녹이기
		melting();
		answer++;
	}
}