#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<int> v;
	cin >> N;

	int total = 0;
	int level = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(),greater<int>());

	int size = v.size() > 42 ? 42 : v.size();
	for (int i = 0; i < size; i++)
	{
		int num = v[i];
		total += num;

		if (num >= 60 && num < 100)
		{
			level++;
		}
		else if (num >= 100 && num < 140)
		{
			level += 2;
		}
		else if (num >= 140 && num < 200)
		{
			level += 3;
		}
		else if (num >= 200 && num < 250)
		{
			level += 4;
		}
		else if (num >= 250)
		{
			level += 5;
		}
	}

	cout << total << ' ' << level;
}