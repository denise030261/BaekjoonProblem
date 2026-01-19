#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
vector<pair<int,int>> v[100001];
bool visited[100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({B,C});
		v[B].push_back({ A,C });
	}

	int target1, target2;
	cin >> target1 >> target2;
	
	int answer = INT_MAX;
	priority_queue<pair<int, int>> pq;
	pq.push({ answer,target1 }); //내림차순이어서 cost를 -처리할 필요 없음

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (visited[current])
		{
			continue;
		}
		visited[current] = true;

		if (current == target2)
		{
			cout << cost;
			break;
		}

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].first;
			int next_cost = v[current][i].second;

			if (!visited[next])
			{
				pq.push({ min(cost,next_cost),next });
			}
		}
	}
}