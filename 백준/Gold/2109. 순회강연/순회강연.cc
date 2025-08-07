#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v[10001];
	int end = 0;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int d, p;
		cin >> p >> d;
		v[d].push_back(p);
		end = max(end, d);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= end; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			pq.push(v[i][j]);
		}

		while (i < pq.size() && !pq.empty())
		{
			pq.pop();
		}
	}

	int answer = 0;
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
}