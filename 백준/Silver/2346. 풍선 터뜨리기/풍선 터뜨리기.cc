#include <iostream>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	deque<pair<int, int>> dq;
	vector<int> answer;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		dq.push_back({ num,i + 1 });
	}

	int dir = 1; // dir이 1은 앞, -1은 뒤
	while (dq.size()!=1)
	{
		int index = -1;
		int order = -1;
		if (dir == 1)
		{
			index = dq.front().second;
			order = dq.front().first;
			dq.pop_front();
		}
		else
		{
			index = dq.back().second;
			order = dq.back().first;
			dq.pop_back();
		}
		answer.push_back(index);

		if (order > 0)
		{
			dir = 1;
			for (int i = 0; i < order - 1; i++)
			{
				int temp_index = dq.front().second;
				int temp_order = dq.front().first;
				dq.pop_front();
				dq.push_back({ temp_order,temp_index });

			}
		}
		else
		{
			dir = -1;
			for (int i = 0; i < abs(order) - 1; i++)
			{
				int temp_index = dq.back().second;
				int temp_order = dq.back().first;
				dq.pop_back();
				dq.push_front({ temp_order,temp_index });
			}
		}
	}
	answer.push_back(dq.front().second);

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << ' ';
	}
}