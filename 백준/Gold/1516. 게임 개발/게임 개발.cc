#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int edges[501] = { 0, };
	int times[501] = { 0, };
	int answer[501] = { 0, };
	vector<int> v[501];
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int time;
		int connect;
		cin >> time;
		times[i] = time;
		while (1)
		{
			cin >> connect;
			if (connect == -1)
				break;

			v[connect].push_back(i);
			edges[i]++;
		}
	}

	queue<int> process;
	for (int i = 1; i <= N; i++)
	{
		if (edges[i] == 0)
		{
			process.push(i);
		}
		answer[i] = times[i];
	}

	while (!process.empty())
	{
		int current = process.front();
		process.pop();

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i];
			edges[next]--;
			answer[next] = max(answer[next], answer[current] + times[next]);
			if (edges[next] == 0)
			{
				process.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << '\n';
	}
}