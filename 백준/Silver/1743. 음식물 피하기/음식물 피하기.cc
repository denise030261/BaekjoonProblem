#include <iostream>
#include <vector>

using namespace std;

int map[100][100] = { 0, };
bool visited[100][100] = { 0, };
int N, M, K;
int answer = 0;
int sum = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x,int y)
{
	answer = max(sum, answer);

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
		{
			if (!visited[next_x][next_y] && map[next_x][next_y]==1)
			{
				visited[next_x][next_y] = true;
				sum++;
				dfs(next_x, next_y);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	vector<pair<int, int>> v;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
		v.push_back({ x - 1,y - 1 });
	}

	for (int i = 0; i < K; i++)
	{
		sum = 0;
		int x = v[i].first;
		int y = v[i].second;
		if (!visited[x][y])
		{
			sum = 1;
			visited[x][y] = true;
			dfs(x, y);
		}
	}

	cout << answer;
}