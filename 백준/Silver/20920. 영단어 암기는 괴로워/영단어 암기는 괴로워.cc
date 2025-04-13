#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
			return a.first < b.first;
		else
			return a.first.length() > b.first.length();
	}

	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	map<string, int> m;
	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str.length() >= M)
		{
			m[str]++;
		}
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << '\n';
	}
}