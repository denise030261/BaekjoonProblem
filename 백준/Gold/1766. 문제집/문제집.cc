#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int count[32001] = { 0, };
	vector<int> edge[32001];
	priority_queue<int,vector<int>,greater<int>> pq;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int first, second;
		cin >> first >> second;
		edge[first].push_back(second);
		count[second]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (count[i] == 0)
		{
			pq.push(i);
		}
	}

	vector<int> answer;
	while (!pq.empty())
	{
		int num = pq.top();
		answer.push_back(num);
		pq.pop();

		for (int i = 0; i < edge[num].size(); i++)
		{
			count[edge[num][i]]--;
			if (count[edge[num][i]] == 0)
			{
				pq.push(edge[num][i]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << ' ';
	}
}