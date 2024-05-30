#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int max_height = 0;
int arr[100][100];
bool visited[100][100] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int answer = 0;

void dfs(int height,int cur_x,int cur_y)
{
	for (int i = 0; i < 4; i++)
	{
		int next_x = cur_x + dx[i];
		int next_y = cur_y + dy[i];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
		{
			if (!visited[next_y][next_x] && arr[next_y][next_x]>height)
			{
				visited[next_y][next_x] = true;
				dfs(height, next_x, next_y);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			max_height = max(max_height, arr[i][j]);
		}
	}

	int sum = 0;
	for (int k = 0; k <= max_height; k++)
	{
		sum = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && arr[i][j] > k)
				{
					visited[i][j] = true;
					dfs(k, j, i);
					sum++;
				}
			}
		}
		answer = max(answer, sum);
	}

	cout << answer;
}