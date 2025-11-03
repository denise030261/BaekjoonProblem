#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<pair<int, int>> v;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({ start,end });
	}
	sort(v.begin(), v.end(),compare);

	int answer = 1;
	int done = v[0].second;
	for (int i = 1; i < N; i++)
	{
		if (done <= v[i].first)
		{
			answer++;
			done = v[i].second;
		}
	}

	cout << answer;
}