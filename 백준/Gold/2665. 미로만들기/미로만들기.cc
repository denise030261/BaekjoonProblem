#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	int map[50][50] = { 0, };
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = str[j] - '0';
		}
	} // 1이 흰방

	priority_queue<pair<int,pair<int, int>>> pq;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	bool visited[50][50] = { 0, };
	pq.push({ 0,{0,0} });
	int answer = 987654321;
	while (!pq.empty())
	{
		int black = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (black >= answer)
		{
			continue;
		}
		if (x == n - 1 && y == n - 1)
		{
			answer = min(answer, black);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n)
			{
				if (!visited[next_x][next_y])
				{
					visited[next_x][next_y] = true;
					if (map[next_x][next_y] == 0)
					{
						pq.push({ -(black + 1),{next_x, next_y} });
					} // 검은 방이면
					else
					{
						pq.push({ -(black),{next_x, next_y} });
					} // 흰 방이면
				}
			}
		}
	}

	cout << answer;
}