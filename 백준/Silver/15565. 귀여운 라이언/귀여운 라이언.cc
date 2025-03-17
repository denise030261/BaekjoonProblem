#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	vector<int> v;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == 1)
		{
			v.push_back(i);
		}
	}

	if (v.size() < K)
	{
		cout << -1;
		return 0;
	}

	int answer = INT_MAX;
	for (int i = 0; i < v.size() - (K-1); i++)
	{
		answer = min(answer, v[i + (K - 1)] - v[i]);
	}
	cout << answer + 1;
}