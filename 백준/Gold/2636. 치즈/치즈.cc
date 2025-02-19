#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
bool visited[100][100] = { 0, };
int cheese[100][100] = { 0, };
int cheese_num = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void outair()
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ 0,0, });
	visited[0][0] = true;
	cheese[0][0] = 2;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N)
			{
				if (!visited[next_y][next_x] && (cheese[next_y][next_x]==0 || cheese[next_y][next_x] == 2))
				{
					visited[next_y][next_x] = true;
					cheese[next_y][next_x] = 2;
					q.push({ next_x,next_y });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int hour = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> cheese[i][j];
			if(cheese[i][j]==1)
				cheese_num++;
		}
	}

	while (cheese_num != 0)
	{
		outair();
		memset(visited, 0, sizeof(visited));
		queue<pair<int, int>> search;
		int last_cheese = 0;
		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (cheese[i][j] == 1 && !visited[i][j])
				{
					search.push({ j,i }); // x,y
					visited[i][j] = true;

					while (!search.empty())
					{
						int x = search.front().first;
						int y = search.front().second;
						search.pop();

						bool connect = false;
						for (int i = 0; i < 4; i++)
						{
							int next_x = x + dx[i];
							int next_y = y + dy[i];
							if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N)
							{
								if (cheese[next_y][next_x] == 2 && !connect)
								{
									connect = true;
									v.push_back({ x,y });
								}
								if (!visited[next_y][next_x] && cheese[next_y][next_x] == 1)
								{
									visited[next_y][next_x] = true;
									search.push({ next_x,next_y });
								}
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			cheese[v[i].second][v[i].first] = 2;
			cheese_num--;
		}
		last_cheese = v.size();

		hour++;
		if (cheese_num <= 0)
		{
			cout << hour << '\n' << last_cheese;
			break;
		}
	}
}