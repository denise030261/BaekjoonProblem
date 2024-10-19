#include <iostream>
#include <queue>
#include<vector>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<pair<int, int>> pq;
	bool visited[50][50] = { 0, };
	int A[50][50] = { 0, };
	int N, R, L;

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	int result = 0;
	bool onceFix = true; // 변동되면 True

	while (onceFix)
	{
		onceFix = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					vector<pair<int, int>> v;
					int dist = 0;
					int count = 0;
					pq.push({ i,j });

					while (!pq.empty())
					{
						int x = pq.top().second;
						int y = pq.top().first;
						v.push_back({ y,x });
						pq.pop();

						if (visited[y][x])
						{
							continue;
						}

						visited[y][x] = true;
						count++;
						dist += A[y][x];

						for (int k = 0; k < 4; k++)
						{
							int next_x = x + dx[k];
							int next_y = y + dy[k];
							if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
							{
								if (!visited[next_y][next_x] && abs(A[next_y][next_x] - A[y][x]) >= L &&
									abs(A[next_y][next_x] - A[y][x]) <= R)
								{
									onceFix = true;
									pq.push({ next_y,next_x });
								}
							}
						}
					}

					for (int k = 0; k < v.size(); k++)
					{
						A[v[k].first][v[k].second] = dist / count;
					}
				
				}
			}
		}

		if (onceFix)
		{
			result++;
		}

		memset(visited, 0, sizeof(visited));
	}

	cout << result;
}