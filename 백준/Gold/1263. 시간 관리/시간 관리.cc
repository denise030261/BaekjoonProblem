#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	vector<pair<int, int>> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int element1, element2;
		cin >> element1 >> element2;
		v.push_back(pair<int, int>(element2, element1));
	}

	sort(v.begin(), v.end());

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (i - 1 >= 0)
		{
			if (v[i].first - v[i].second < 0)
			{
				cout << -1;
				return 0;
			}
			else if (v[i].first - v[i].second <= v[i - 1].first)
			{
				v[i - 1].first = v[i].first - v[i].second;
			}
			else if(v[i].first - v[i].second > v[i - 1].first)
			{
				continue;
			}
		}
		else if (i - 1 == -1)
		{
			if (v[i].first - v[i].second < 0)
			{
				cout << -1;
				return 0;
			}
			cout << v[i].first - v[i].second;
			return 0;
		}
	}
}