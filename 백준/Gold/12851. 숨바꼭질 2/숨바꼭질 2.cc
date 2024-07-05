#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	int time = 987654321;
	bool visited[100001] = { 0, };
	int method = 0;
	queue<pair<int, int>> q;
	cin >> N >> K;

	q.push({ 0,N });
	visited[N] = true;
	while (!q.empty())
	{
		int curDist = q.front().second;
		int curCost = q.front().first;
		q.pop();
		visited[curDist] = true;

		if (curDist == K)
		{
			if (curCost == time)
			{
				method++;
			}
			else if (curCost < time)
			{
				time = curCost;
				method = 1;
			}
			visited[curDist] = false;
			continue;
		}

		if (time > curCost + 1)
		{
			if (curDist - 1 >= 0)
			{
				if (!visited[curDist - 1])
				{
					q.push({ curCost + 1, curDist - 1 });
				}
			}
			if (curDist + 1 <= 100000 )
			{
				if (!visited[curDist + 1])
				{
					q.push({ curCost + 1, curDist + 1 });
				}
			}
			if (curDist * 2 <= 100000 )
			{
				if (!visited[curDist * 2])
				{
					q.push({ curCost + 1, curDist * 2 });
				}
			}
		}
	}

	cout << time << '\n' << method;
}