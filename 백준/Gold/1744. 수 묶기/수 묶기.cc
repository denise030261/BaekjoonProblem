#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	long int answer = 0;
	vector<int> pos;
	vector<int> neg;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num > 0)
			pos.push_back(num);
		else
			neg.push_back(num);
	}
	sort(pos.begin(), pos.end(),greater<int>());
	sort(neg.begin(),neg.end());

	bool used[50] = { 0, };
	for (int i = 0; i < pos.size(); i++)
	{
		if (used[i])
		{
			continue;
		}

		int select = -1;
		int difference = 0;
		for (int j = i + 1; j < pos.size(); j++)
		{
			if ((pos[i] + pos[j] < pos[i] * pos[j]) && !used[j])
			{
				if ((select != -1 && abs((pos[i] + pos[j]) - (pos[i] * pos[j])) > difference)
					|| select == -1)
				{
					select = j;
					difference = abs((pos[i] + pos[j]) - (pos[i] * pos[j]));
				}
			}
		}

		used[i] = true;
		if (select == -1)
		{
			answer += pos[i];
			//cout << answer << '\n';
		}
		else
		{
			used[select] = true;
			answer += pos[i] * pos[select];
			//cout << pos[i] * pos[select] << ' ' << answer << '\n';
		}
	}

	for (int i = 0; i < neg.size(); i++)
	{
		used[i] = false;
	}

	for (int i = 0; i < neg.size(); i++)
	{
		if (used[i])
		{
			continue;
		}

		int select = -1;
		int difference = 0;
		for (int j = i + 1; j < neg.size(); j++)
		{
			if ((neg[i] + neg[j] < neg[i] * neg[j]) && !used[j])
			{
				if ((select != -1 && abs((neg[i] + neg[j]) - (neg[i] * neg[j])) > difference)
					|| select == -1)
				{
					select = j;
					difference = abs((neg[i] + neg[j]) - (neg[i] * neg[j]));
				}
			}
		}

		used[i] = true;
		if (select == -1)
		{
			answer += neg[i];
			//cout << answer << '\n';
		}
		else
		{
			used[select] = true;
			answer += neg[i] * neg[select];
			//cout << neg[i] * neg[select] << ' ' << answer << '\n';
		}
	}

	cout << answer;
}