#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int degree[1001] = { 0, };
	vector<int>  v[1001];
	vector<int> answer;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int order;
		int pre = -1;
		cin >> order;
		for (int j = 0; j < order; j++)
		{
			int num;
			cin >> num;

			if (pre == -1)
			{
				pre = num;
			}
			else
			{
				v[pre].push_back(num);
				pre = num;
				degree[num]++;
			}
		}
	}

	queue<int> process;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			process.push(i);
		}
	}

	while (!process.empty())
	{
		int enter = process.front();
		answer.push_back(enter);
		process.pop();

		for (int i = 0; i < v[enter].size(); i++)
		{
			degree[v[enter][i]]--;
			if (degree[v[enter][i]] == 0)
			{
				process.push(v[enter][i]);
			}
		}
	}

	if (answer.size() != N)
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}
}