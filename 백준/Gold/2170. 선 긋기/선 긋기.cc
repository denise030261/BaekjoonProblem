#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[300000] = { 0, };
int pre_middle = -1;
vector<int> bags;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	vector<pair<int, int>> v;
 	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	long int answer = 0;
	int start = v[0].first;
	int end = v[0].second;
	for (int i = 1; i < N; i++)
	{
		if (v[i].first <= end && v[i].second>end)
		{
			end = v[i].second;
		}
		else if (v[i].first > end)
		{
			answer += end - start;
			start = v[i].first;
			end = v[i].second;
		}
	}
	answer += end - start;

	cout << answer;
}