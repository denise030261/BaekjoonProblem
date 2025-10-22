#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<int> v;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	priority_queue<int> Lpq;
	priority_queue<int, vector<int>, greater<int>> Rpq;

	cout << v[0] << '\n';
	if (v[0] < v[1])
	{
		Lpq.push(v[0]);
		Rpq.push(v[1]);
		cout << v[0] << '\n';
	}
	else
	{
		Lpq.push(v[1]);
		Rpq.push(v[0]);
		cout << v[1] << '\n';
	}

	while (Lpq.size() + Rpq.size() < N)
	{
		int idx = Lpq.size() + Rpq.size();
		if (Lpq.top() >= v[idx])
		{
			Lpq.push(v[idx]);
		}
		else
		{
			Rpq.push(v[idx]);
		}

		if ((Lpq.size() + Rpq.size()) % 2 == 0)
		{
			if (Lpq.size() != Rpq.size())
			{
				if (Lpq.size() < Rpq.size())
				{
					Lpq.push(Rpq.top());
					Rpq.pop();
				}
				else
				{
					Rpq.push(Lpq.top());
					Lpq.pop();
				}
			}
		}
		else
		{
			if (Lpq.size() - Rpq.size() != 1)
			{
				if (Lpq.size() < Rpq.size())
				{
					Lpq.push(Rpq.top());
					Rpq.pop();
				}
				else
				{
					Rpq.push(Lpq.top());
					Lpq.pop();
				}
			}
		}

		cout << Lpq.top() << '\n';
	}
}