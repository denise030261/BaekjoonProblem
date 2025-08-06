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

	for (int i = 0; i < (int)pos.size()-1; i+=2)
	{
		if (pos[i + 1] == 1)
		{
			answer += pos[i] + pos[i + 1];
		}
		else
		{
			answer += pos[i] * pos[i + 1];
		}
	}
	if (pos.size() % 2 == 1)
	{
		answer += pos[pos.size() - 1];
	}

	for (int i = 0; i < (int)neg.size() - 1; i += 2)
	{
		answer += neg[i] * neg[i + 1];
	}
	if (neg.size() % 2 == 1)
	{
		answer += neg[neg.size() - 1];
	}
	cout << answer;
}