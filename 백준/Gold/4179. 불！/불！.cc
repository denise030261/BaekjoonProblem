#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int R, C;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool possible(int x,int y)
{
	return (x>= 0 && x< R && y >= 0 && y < C);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char map[1001][1001];
	int fires[1001][1001];
	queue<pair<int, pair<int, int>>> firesLoc;
	priority_queue<pair<int, pair<int, int>>> pq;
	bool visited[1001][1001] = { 0, };

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			map[i][j] = str[j];
			fires[i][j] = INT_MAX;

			if (map[i][j] == 'J')
			{
				pq.push({ 0,{i,j} });
			}
			else if (map[i][j] == 'F')
			{
				fires[i][j] = 0;
				firesLoc.push({ 0,{ i,j } });
			}
		}
	}

	while (!firesLoc.empty())
	{
		int cost = firesLoc.front().first;
		int x = firesLoc.front().second.first;
		int y = firesLoc.front().second.second;
		firesLoc.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (possible(next_x, next_y))
			{
				if (!visited[next_x][next_y] && map[next_x][next_y] != '#')
				{
					visited[next_x][next_y] = true;
					fires[next_x][next_y] = min(cost + 1, fires[next_x][next_y]);
					firesLoc.push({ cost + 1,{next_x,next_y} });
				}
			}
		}
	}

	memset(visited, 0, sizeof(visited));
	int answer = INT_MAX;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (possible(next_x, next_y))
			{
				if (!visited[next_x][next_y] && map[next_x][next_y] != '#' && cost+1<fires[next_x][next_y])
				{
					visited[next_x][next_y] = true;
					pq.push({ -(cost + 1),{next_x,next_y} });
				}
			}
			else
			{
				answer = min(answer, cost + 1);
			}
		}
	}

	if (answer == INT_MAX)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << answer;
	}
}