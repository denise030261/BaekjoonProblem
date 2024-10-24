#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int answer = 0;
	long long int sum = 0;
	vector<pair<long long int, long long int>> v;
	int N;
	cin >> N;

	long long int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end());

	for(int i = 1; i <= N; i++)
	{
		answer += v[i - 1].first * i + v[i - 1].second;
	}
	cout << answer;
}