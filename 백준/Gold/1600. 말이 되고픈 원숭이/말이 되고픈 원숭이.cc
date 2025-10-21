#include <iostream>
#include <climits>
#include <queue>

using namespace std;
// 맨 왼쪽 위 -> 맨 오른쪽 아래
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K, W, H;
	int map[201][201] = { 0, };
	int costMap[201][201][31] = {0,};
	cin >> K >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
			for(int k=0;k<=K;k++)
				costMap[i][j][k] = INT_MAX;
		}
	}

	priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
	pq.push({ {0,-K} ,{ 0,0 } });

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int horsex[8] = { 1,1,2,2,-1,-1,-2,-2 };
	int horsey[8] = { 2,-2,1,-1,2,-2,1,-1 };
	int answer = INT_MAX;
	while (!pq.empty())
	{
		int cost = -pq.top().first.first;
		int horseCost = -pq.top().first.second;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (x == H - 1 && y == W - 1)
		{
			answer = min(answer, cost);
			continue;
		}

		if (horseCost > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int next_x = x + horsex[i];
				int next_y = y + horsey[i];
				if (next_x >= 0 && next_x < H && next_y >= 0 && next_y < W)
				{
					if (!map[next_x][next_y] && costMap[next_x][next_y][horseCost - 1] > cost + 1)
					{
						costMap[next_x][next_y][horseCost - 1] = cost + 1;
						pq.push({ {-(cost + 1),-(horseCost - 1)} ,{next_x,next_y} });
						//cout << cost + 1 << ' ' << horseCost << ' ' << next_x << ' ' << next_y << '\n';
					}
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < H && next_y >= 0 && next_y < W)
			{
				if (!map[next_x][next_y] && costMap[next_x][next_y][horseCost] > cost + 1)
				{
					costMap[next_x][next_y][horseCost] = cost + 1;
					pq.push({ {-(cost + 1),-horseCost} ,{next_x,next_y} });
					//cout << cost + 1 << ' ' << horseCost << ' ' << next_x << ' ' << next_y << '\n';
				}
			}
		}
	}

	if (answer == INT_MAX)
		cout << -1;
	else
		cout << answer;
}