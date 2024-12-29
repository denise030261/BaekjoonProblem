#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, L;
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N >> L;

	int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}

	while (!pq.empty())
	{
		answer++;
		int circle = L;
		int start = pq.top();
		while (circle != 0 && !pq.empty())
		{
			if (start == pq.top())
				pq.pop();

			start++;
			circle--;
		}
	}

	cout << answer;
}