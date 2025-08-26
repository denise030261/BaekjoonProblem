#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int map[65][65] = { 0, };
bool visited[65][65] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, Q,L;
int loaf = 0;

void dfs(int x, int y,int sum) 
{
	loaf = max(sum, loaf);

	for (int i = 0; i < 4; i++) 
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		int map_size = 1<<N;
		if (next_x >= 0 && next_x < map_size && next_y >= 0 && next_y < map_size) 
		{
			if (!visited[next_x][next_y] && map[next_x][next_y] > 0) 
			{
				visited[next_x][next_y] = true;
				dfs(next_x, next_y, sum + 1);
			}
		}
	}
}

void turn(int x_start, int y_start)
{
	vector<int> v;
	int index = 0;
	int preMap[65][65] = { 0, };
	int size = 1 << L;
	for (int i = x_start; i < x_start + size; i++)
	{
		for (int j = y_start; j < y_start + size; j++)
		{
			v.push_back(map[i][j]);
		}
	}

	for (int i = y_start + size - 1; i >= y_start; i--)
	{
		for (int j = x_start; j < x_start + size; j++)
		{
			map[j][i] = v[index];
			index++;
		}
	}
}

void ice()
{
	int size = 1 << N;
	vector<pair<int, int>> v;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				int next_x = i + dx[k];
				int next_y = j + dy[k];

				if (next_x >= 0 && next_x < size && next_y >= 0 && next_y < size)
				{
					if (map[next_x][next_y] > 0)
					{
						sum++;
					}
				}
			}

			if (sum < 3  && map[i][j]>0)
			{
				v.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		map[x][y]--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v;
	int size = 0;

	cin >> N >> Q;
	
	size = 1 << N;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < Q; i++)
	{
		cin >> L;
		
		for (int j = 0; j < size; j+=1<<L)
		{
			for (int k = 0; k < size; k+= 1 << L)
			{
				turn(j, k);
			}
		}

		ice();
	}

	int total = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			total += map[i][j];

			if (!visited[i][j] && map[i][j] > 0)
			{
				visited[i][j] = true;
				
				queue<pair<int, int>> q;
				q.push({ i,j });
				int answer = 0;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					answer++;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int next_x = x + dx[k];
						int next_y = y + dy[k];

						int map_size = 1 << N;
						if (next_x >= 0 && next_x < map_size && next_y >= 0 && next_y < map_size)
						{
							if (!visited[next_x][next_y] && map[next_x][next_y] > 0)
							{
								visited[next_x][next_y] = true;
								q.push({ next_x,next_y });
							}
						}
					}
				}

				loaf = max(loaf, answer);
			}
		}
	}

	cout << total << '\n' << loaf;
}