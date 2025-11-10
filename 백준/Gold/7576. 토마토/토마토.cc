#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <tuple>
#include <queue>
#include <string>
using namespace std;
int M, N;
int num = 0;
int arr[1000][1000];
int visit[1000][1000] = { 0, };
queue<pair<int, int>> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y)
{
	visit[x][y] = 1;
	q.push({ x,y });

	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			int temp_x = get<0>(q.front());
			int temp_y = get<1>(q.front());

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int new_x = temp_x + dx[i];
				int new_y = temp_y + dy[i];

				if ((0 <= new_x && new_x < M) && (0 <= new_y && new_y < N) &&
					!visit[new_x][new_y] && arr[new_x][new_y] == 0 && arr[temp_x][temp_y] == 1)
				{
					visit[new_x][new_y] = 1;
					arr[new_x][new_y] = 1;
					q.push({ new_x,new_y});
				}
			}
		}
		num++;
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					q.push({ i,j });
			}

	bfs(get<0>(q.front()), get<1>(q.front()));

		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
				if (arr[i][j] == 0)
				{
					cout << -1;
					return 0;
				}

	cout << num - 1;
}

