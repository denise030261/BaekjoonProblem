#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bool visited[50][50][50] = { 0, };
	char map[50][50][50] = { 0, };

	int L, R, C;
	cin >> L >> R >> C;
	while (L != 0 && R != 0 && C != 0)
	{
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				for (int k = 0; k < 50; k++)
				{
					visited[i][j][k] = false;
					map[i][j][k] = ' ';
				}
			}
		}
		
		pair<int, pair<int, int>> start;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				string str;
				cin >> str;
				for (int k = 0; k < C; k++)
				{
					visited[i][j][k] = false;
					map[i][j][k] = str[k];

					if (str[k] == 'S')
					{
						start = { i,{j,k} };
					}
				}
			}
		} // 입력 받기

		priority_queue<pair<int, pair<int, pair<int, int>>>> pq;
		pq.push({ 0,start });
		visited[start.first][start.second.first][start.second.second] = true;
		int dz[6] = { 1,-1,0,0,0,0 };
		int dy[6] = { 0,0,1,-1,0,0 };
		int dx[6] = { 0,0,0,0,1,-1 };
		
		int answer = INT_MAX;
		while (!pq.empty())
		{
			int z = pq.top().second.first;
			int y = pq.top().second.second.first;
			int x = pq.top().second.second.second;
			int sum = -pq.top().first;
			//cout << z << ' ' << y << ' ' << x << ' ' << sum << '\n';
			pq.pop();

			for (int i = 0; i < 6; i++)
			{
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				int next_z = z + dz[i];

				if (next_x >= 0 && next_x < C && next_y >= 0 && next_y < R && next_z >= 0 && next_z < L)
				{
					if (!visited[next_z][next_y][next_x])
					{
						if (map[next_z][next_y][next_x] == '.')
						{
							pair<int, pair<int, int>> point = { next_z,{next_y,next_x} };
							visited[next_z][next_y][next_x] = true;
							pq.push({ -(sum + 1), point });
						}
						else if (map[next_z][next_y][next_x] == 'E')
						{
							answer = min(sum + 1, answer);
						}
					}
				}
			}
		}

		if (INT_MAX == answer)
		{
			cout << "Trapped!\n";
		}
		else
		{
			cout << "Escaped in "<<answer<<" minute(s).\n";
		}

		cin >> L >> R >> C;
	}
}