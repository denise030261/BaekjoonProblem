#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int N;
int s = 0;
vector<pair<long long , long long>> v;
long long answer = LLONG_MAX;

void dfs(long long bittle, long long sweat,int num, long long diff)
{
	answer = min(answer, diff);

	for (int i = num; i < N; i++)
	{
		dfs(bittle * v[i].first, sweat + v[i].second, i + 1, abs((bittle * v[i].first)- (sweat + v[i].second)));
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	dfs(1, 0, 0, answer);
	
	cout << answer;
}