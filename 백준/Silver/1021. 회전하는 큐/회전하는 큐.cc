#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	deque<int> dq;
	deque<int> num;
	int N, M,number;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> number;
		num.push_back(number);
	}
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	int move = 0;

	while (!num.empty())
	{
		int target = num.front();

		deque<int> dqOne;
		deque<int> dqTwo;
		dqOne = dq;
		dqTwo = dq;

		int plusnumOne = 0;
		while (1)
		{
			if (dqOne.front() == target)
			{
				dqOne.pop_front();
				break;
			}
			else
			{
				int temp = dqOne.front();
				dqOne.pop_front();
				dqOne.push_back(temp);
				plusnumOne++;
			}
		}
		int plusnumTwo = 1;
		while (1)
		{
			if (dqTwo.back() == target)
			{
				dqTwo.pop_back();
				break;
			}
			else
			{
				int temp = dqTwo.back();
				dqTwo.pop_back();
				dqTwo.push_front(temp);
				plusnumTwo++;
			}
		}

		num.pop_front();
		if (plusnumOne > plusnumTwo)
		{
			move += plusnumTwo;
			dq = dqTwo;
		}
		else
		{
			move += plusnumOne;
			dq = dqOne;
		}
	}

	cout << move;
}