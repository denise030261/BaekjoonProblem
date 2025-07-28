#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
	if (a.first == b.first)
		return a.second > b.second;

	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<pair<int, int>> v;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int deadline, score;
		cin >> deadline >> score;
		v.push_back({ deadline,score });
	}
	
	sort(v.begin(), v.end(),compare);

	int day = v[0].first;
	int answer = 0;
	while (day != 0)
	{
		int index = 0;
		int get = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (day <= v[i].first && get<v[i].second)
			{
				get = v[i].second;
				index = i;
			}
			else if (day > v[i].first)
			{
				break;
			}
		}

		answer += get;
		if(get!=0)
			v.erase(v.begin() + index);
		day--;
	}

	cout << answer;
}