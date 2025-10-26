#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool check[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int a[51][51];

void dfs(int x, int y, int n, int m)
{
	check[x][y] = true;
	for (int i = 0; i < 4; i++) 
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (a[nx][ny] == 1)
				if (!check[nx][ny])
					dfs(nx, ny, n, m);
		}

		else continue;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, M, N, K;
	cin >> T;

	while (T != 0)
	{
		cin >> M >> N >> K;
		int num = 0;
		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			a[Y][X] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if(a[i][j]==1)
					if (!check[i][j])
					{
						num++;
						dfs(i, j, N, M);
					}
			}
		}

		cout << num << '\n';
		T--;
		memset(a, 0, sizeof(a));
		memset(check, false, sizeof(check));
	}
}