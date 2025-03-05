#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	bool visited[100001] = { 0, };
	int track[100001] = { 0, };
	int answer = INT_MAX;
	priority_queue<pair<int, int>> pq;
	cin >> N >> K;

	pq.push({ -0,N });
	visited[N] = true;
	while (!pq.empty())
	{
		int sum = -pq.top().first;
		int step = pq.top().second;
		pq.pop();

		if (K == step)
		{
			answer = min(answer, sum);
		}
		if (sum + 1 >= answer)
		{
			break;
		}

		if (step * 2 <= 100000 && !visited[step * 2])
		{
			visited[step * 2] = true;
			track[step * 2] = step;
			pq.push({ -(sum + 1),step * 2 });
		}
		if (step + 1 <= 100000 && !visited[step + 1])
		{
			visited[step + 1] = true;
			track[step + 1] = step;
			pq.push({ -(sum + 1),step + 1 });
		}
		if (step - 1 >= 0 && !visited[step - 1])
		{
			visited[step - 1] = true;
			track[step - 1] = step;
			pq.push({ -(sum+1),step - 1 });
		}
	}

	cout << answer << '\n';
	vector<int> v;
	v.push_back(K);
	int cont = K;
	for (int i = 0; i < answer; i++)
	{
		v.push_back(track[cont]);
		cont = track[cont];
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i] << ' ';
	}
}