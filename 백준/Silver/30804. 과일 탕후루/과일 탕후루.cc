#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	queue<int> q;
	int kinds[10] = { 0, };
	int N;
	cin >> N;

	int kind = 0;
	int answer = 0;
	int sum = 0;

	while (N--) 
	{
		int num;
		cin >> num;
		q.push(num);
		sum++;

		if (kinds[num] == 0)
		{
			kind++;
		}
		kinds[num]++;

		while (kind > 2) 
		{
			int fruit = q.front();
			kinds[fruit]--;
			q.pop();
			sum--;
			if (kinds[fruit] == 0)
			{
				kind--;
			}
		}
		answer = max(answer, sum);
	}

    cout << answer;
}