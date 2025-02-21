#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	int answer = INT_MAX;
	queue<pair<int, int>> broken;
	int map[1000][1000] = { 0, };
	cin >> N >> M; // N은 y축, M은 x축

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			map[i][j] = str[j] - '0';
			if (map[i][j] == 1)
			{
				broken.push({ j, i });
			}
		}
	}

	queue<pair<pair<int, bool>, pair<int, int>>> road;
	bool visited[1000][1000] = { 0, };
	bool broken_visited[1000][1000] = { 0, };
	road.push({ {1,false} ,{ 0,0 } });
	visited[0][0] = true;
	while (!road.empty())
	{
		int total = road.front().first.first; // distance
		bool dobreak = road.front().first.second; // break?
		int x = road.front().second.first; 
		int y = road.front().second.second; 
		road.pop();

		if (x == M - 1 && y == N - 1)
		{
			answer = min(answer, total);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N)
			{
				if (dobreak)
				{
					if (map[next_y][next_x] == 0 && !broken_visited[next_y][next_x])
					{
						broken_visited[next_y][next_x] = true;
						road.push({ {total + 1,dobreak}, { next_x,next_y } });
					}
				}
				else
				{
					if (map[next_y][next_x] == 0 && !visited[next_y][next_x])
					{
						visited[next_y][next_x] = true;
						road.push({ {total + 1,dobreak}, { next_x,next_y } });
					}
					else if (map[next_y][next_x] == 1 && !broken_visited[next_y][next_x])
					{
						broken_visited[next_y][next_x] = true;
						road.push({ {total + 1,!dobreak}, { next_x,next_y } });
					}
				}
			}
		}
	}

	if (answer == INT_MAX)
		cout << -1;
	else
		cout << answer;
}