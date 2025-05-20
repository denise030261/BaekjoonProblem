#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<int> v[10001];
	int answers[10001] = { 0, };
	int answer = 0;
	bool visited[10001] = { 0, };

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		v[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		queue<int> q;
		q.push(i);

		answers[i]++;
		visited[i] = true;
		while (!q.empty())
		{
			int current = q.front();
			q.pop();

			for (int j = 0; j < v[current].size(); j++)
			{
				if (!visited[v[current][j]])
				{
					visited[v[current][j]] = true;
					answers[i]++;
					q.push(v[current][j]);
				}
			}
		}

		answer = max(answer, answers[i]);
		memset(visited, 0, sizeof(visited));
	}

	for (int i = 1; i <= N; i++)
	{
		if (answer == answers[i])
			cout << i << ' ';
	}
}