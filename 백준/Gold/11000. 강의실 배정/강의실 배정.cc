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
	cin >> N;
	
	long long int start, end;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		v.push_back({ start,end });
	}
	sort(v.begin(), v.end());

	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(v[0].second);

	for (int i = 1; i < N; i++)
	{
		pq.push(v[i].second);
		if (v[i].first >= pq.top())
			pq.pop();
	}

	cout << pq.size();
}