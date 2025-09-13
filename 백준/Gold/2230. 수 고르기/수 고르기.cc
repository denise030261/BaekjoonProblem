#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<long int> v;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		long int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	int start = 0;
	int end = 0;

	long int answer = INT_MAX;
	while (start <= end && end<N)
	{
		if (v[end] - v[start] >= M)
		{
			answer = min(answer, v[end] - v[start]);
			start++;
		}
		else
		{
			end++;
		}
	}

	cout << answer;
}