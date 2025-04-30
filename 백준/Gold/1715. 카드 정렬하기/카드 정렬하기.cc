#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<long long int> pq;
	long long int answer = 0;
	int N;

	cin >> N;
	long long int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(-num);
	}

	while (pq.size()>1)
	{
		long long int a = pq.top();
		pq.pop();
		long long int b = pq.top();
		pq.pop();

		answer += a + b;
		pq.push(a + b);
	}

	cout << -answer;
}