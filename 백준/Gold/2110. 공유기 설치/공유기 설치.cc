#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<long long int> v;
	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		long long int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long int low = 1;
	long long int high = v[v.size() - 1]-v[0];
	long long int answer = 0;
	while (low <= high)
	{
		long long int mid = (low + high) / 2;
		long long int start = v[0];
		long long int length = 0;
		long long int sum = 1;

		for (int i = 0; i < v.size(); i++)
		{
			length = v[i] - start;
			if (length >= mid)
			{
				sum++;
				start = v[i];
			}
		}

		if (sum < C)
		{
			high = mid - 1;
		}
		else
		{
			answer = max(answer, mid);
			low = mid + 1;
		}
	}

	cout << answer;
}