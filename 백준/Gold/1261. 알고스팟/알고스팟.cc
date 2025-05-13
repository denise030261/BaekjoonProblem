#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	int map[100][100];
	bool visited[100][100] = { 0, };

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	int answer = INT_MAX;
	priority_queue<pair<int, pair<int, int>>> pq;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	pq.push({ 0,{0,0} }); // 부순 횟수, y위치, x위치
	visited[0][0] = true;
	while (!pq.empty())
	{
		int broke = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		if (y == M - 1 && x == N - 1)
		{
			answer = min(answer, broke);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
			{
				if (!visited[next_y][next_x])
				{
					visited[next_y][next_x] = true;
					pq.push({ (map[next_y][next_x] == 1 ? -(broke + 1) : -broke),{next_y,next_x} });
				}
			}
		}
	}

	cout << answer;
}