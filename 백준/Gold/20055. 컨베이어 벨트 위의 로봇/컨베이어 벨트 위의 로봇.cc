#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = 0;
	int zero = 0;
	vector<int> robots; // 로봇 위치
	int belt[200] = { 0, }; // 벨트 내구도
	bool exist[200] = { 0, }; // 로봇 존재 여부
	int N, K;
	
	cin >> N >> K;
	for (int i = 0; i < 2*N; i++)
	{
		cin >> belt[i];
	}

	while (zero < K)
	{
		zero = 0;
		for (int i = 0; i < robots.size(); i++)
		{
			exist[robots[i]] = false;
			robots[i]++;
			exist[robots[i]] = true;

			if (robots[i] == N - 1)
			{
				robots.erase(robots.begin() + i);
				exist[N - 1] = false;
				i--;
			}
		}

		int temp;
		temp = belt[2 * N - 1];
		for (int i = 2 * N - 1; i > 0; i--) 
		{
			belt[i] = belt[i - 1];
		}
		belt[0] = temp;

		for (int i = 0; i < robots.size(); i++)
		{
			int next = robots[i] + 1;
			if (!exist[next] && belt[next]>0)
			{
				exist[robots[i]] = false;
				robots[i]++;
				exist[robots[i]] = true;
				belt[robots[i]]--;

				if (robots[i] == N - 1)
				{
					robots.erase(robots.begin() + i);
					exist[N-1] = false;
					i--;
				}
			}
		}

		if (belt[0] > 0)
		{
			robots.push_back(0);
			belt[0]--;
			exist[0] = true;
		}

		for (int i = 0; i < 2 * N; i++)
		{
			if (belt[i] == 0)
				zero++;
		}

		answer++;
	}

	cout << answer;
}