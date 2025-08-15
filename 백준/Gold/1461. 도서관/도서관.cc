#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
bool turn = true;
deque<int> d;

bool Judge()
{
	if (d.empty())
		return true;
	if (turn && d.front() > 0 || !turn && d.front() < 0)
	{
		reverse(d.begin(), d.end());
		turn = !turn;
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	int standard = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		d.push_back(num);

		if (abs(num) > standard)
		{
			standard = abs(num);
			if (num > 0)
			{
				turn = false;
			}
			else
			{
				turn = true;
			}
		}
	}
	if (turn)
	{
		sort(d.begin(), d.end());
	}
	else
	{
		sort(d.begin(), d.end(), greater<int>());
	}

	int answer = -abs(d.front());
	while (!d.empty())
	{
		Judge();
		answer += 2*abs(d.front());
		for (int i = 0; i < M; i++)
		{
			if (d.empty() || Judge())
				break;
			d.pop_front();
		}
	}
	cout << answer;
}