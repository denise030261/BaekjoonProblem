#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int V, E;
	int answer = INT_MAX;
	int map[401][401] = { 0, };
	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			map[i][j] = 1000000000;
		}
	}

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
	}

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int k = 1; k <= V; k++)
			{
				map[j][k] = min(map[j][i] + map[i][k], map[j][k]);
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		answer = min(answer, map[i][i]);
	}

	if (answer == 1000000000)
		answer = -1;

	cout << answer;
}