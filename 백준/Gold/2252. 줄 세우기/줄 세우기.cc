#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int edge[32001] = { 0, };
	vector<int> answer;
	vector<int> v[32001];
	queue<int> q;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int first, second;
		cin >> first >> second;

		v[first].push_back(second);
		edge[second]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (edge[i] == 0)
		{
			q.push(i);
		}
	}

	while (N != answer.size())
	{
		int current = q.front();
		q.pop();

		answer.push_back(current);
		for (int i = 0; i < v[current].size(); i++)
		{
			edge[v[current][i]]--;
			if (edge[v[current][i]] == 0)
			{
				q.push(v[current][i]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
}