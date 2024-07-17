#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, N, X;
	cin >> N >> M >> X;
	int graph[1001][1001] = { 0, };

	fill(&graph[0][0], &graph[0][0] + sizeof(graph) / sizeof(int), 987654321);

	for (int i = 0; i < M; i++)
	{
		int start, end, time;
		cin >> start >> end >> time;
		graph[start][end] = time;
	}

	for (int k = 1; k <= N; k++)
	{
		graph[k][k] = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, graph[i][X] + graph[X][i]);
	}
	cout << answer;
}