#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <tuple>
#include <queue>
#include <string>
using namespace std;
int M, N, H;
int num = 0;
int arr[100][100][100];
int visit[100][100][100] = {0,};
queue<tuple<int, int, int>> q;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

void bfs(int x, int y, int z)
{
	visit[x][y][z] = 1;
	q.push({ x,y,z });

	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			int temp_x = get<0>(q.front());
			int temp_y = get<1>(q.front());
			int temp_z = get<2>(q.front());

			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int new_x = temp_x + dx[i];
				int new_y = temp_y + dy[i];
				int new_z = temp_z + dz[i];

				if ((0 <= new_x && new_x < M) && (0 <= new_y && new_y < N) && (0 <= new_z && new_z < H) &&
					!visit[new_x][new_y][new_z] && arr[new_x][new_y][new_z] == 0 && arr[temp_x][temp_y][temp_z] == 1)
				{
					visit[new_x][new_y][new_z] = 1;
					arr[new_x][new_y][new_z] = 1;
					q.push({ new_x,new_y,new_z });
				}
			}
		}
		num++;
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
					q.push({ i,j,k });
			}
	
	bfs(get<0>(q.front()), get<1>(q.front()), get<2>(q.front()));

	for (int k = 0; k < H; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
				if (arr[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}

	cout << num-1;
}

