#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<long long int, vector<long long int>,greater<long long int>> pq;
	int n, m, num;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++)
	{
		long long int first = pq.top();
		pq.pop();
		long long int second = pq.top();
		pq.pop();

		pq.push(first + second);
		pq.push(first + second);
	}

	long long int answer = 0;
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
}