#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, w, L;
	vector<int> v;
	cin >> n >> w >> L;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	int weigh = 0;
	int time = 0;
	queue<pair<int, int>> q; // 무게 거리
	for (int i = 0; i < v.size(); i++)
	{
		if (weigh + v[i] <= L)
		{
			int circle = q.size();
			for (int j = 0; j < circle; j++)
			{
				int curWeigh = q.front().first;
				int curDis = q.front().second;
				q.pop();
				curDis++;
				if (curDis == w)
				{
					weigh -= curWeigh;
				}
				else
				{
					q.push({ curWeigh,curDis });
				}
			}
			q.push({ v[i],0 });
			weigh += v[i];
			time++;
		}
		else
		{
			int curTime = 0;
			while (!q.empty())
			{
				int curWeigh = q.front().first;
				int curDis = q.front().second;
				q.pop();

				curTime = max(curTime, w - curDis);
				weigh -= curWeigh;
				if (weigh + v[i] <= L)
				{
					int circle = q.size();
					for (int j = 0; j < circle; j++)
					{
						int curWeigh = q.front().first;
						int curDis = q.front().second;
						q.pop();
						curDis+= curTime;
						q.push({ curWeigh,curDis });
					}
					break;
				}
			}
			time += curTime;
			q.push({ v[i],0 });
			weigh += v[i];
		}

		//cout << time << '\n';
	}

	while (!q.empty())
	{
		int curWeigh = q.front().first;
		int curDis = q.front().second;
		q.pop();

		if (q.size() == 0)
		{
			time += w - curDis;
		}
	}
	cout << time;
}