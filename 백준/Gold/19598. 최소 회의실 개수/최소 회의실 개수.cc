#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<pair<int, int>> v;
	vector<int> places;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({ start,end });
	}
	sort(v.begin(), v.end());

	priority_queue<int> q;
	for (int i = 0; i < N; i++)
	{
		if (!q.empty())
		{
			if (-q.top() <= v[i].first)
			{
				q.pop();
			}
		}
		q.push(-v[i].second);
	}
	cout << q.size();
}