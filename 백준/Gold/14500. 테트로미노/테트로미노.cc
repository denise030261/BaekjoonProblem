#include <iostream>
#include <climits>

using namespace std;

int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int arr[500][500];
bool visited[500][500];
int answer = 0;
int preanswer = 0;
int roote = 0;

void dfs(int x,int y)
{
	roote++;
	preanswer+=arr[x][y];

	if (roote == 4)
	{
		answer = max(answer, preanswer);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y <M)
		{
			if (!visited[next_x][next_y])
			{
				visited[next_x][next_y] = true;
				dfs(next_x, next_y);
				visited[next_x][next_y] = false;
				roote--;
				preanswer -= arr[next_x][next_y];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = true;
				dfs(i, j);
				visited[i][j] = false;
				roote--;
				preanswer -= arr[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			roote = 0;
			preanswer = 0;

			if (!((i == 0 && j == 0) || (i == 0 && j == M-1)) || (i == N-1 && j == 0) || (i == N-1 && j == M-1))
			{
				int Min = INT_MAX;
				preanswer += arr[i][j];
				roote++;

				for (int k = 0; k < 4; k++)
				{
					int next_x = i + dx[k];
					int next_y = j + dy[k];

					if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
					{
						Min = min(Min, arr[next_x][next_y]);

						preanswer += arr[next_x][next_y];
						roote++;
					}
				}

				if (roote == 5)
				{
					preanswer -= Min;
				}

				answer = max(answer, preanswer);
			}
		}
	}
	
	cout << answer;
}