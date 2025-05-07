#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	long long int low = 1;
	long long int high = 0;

	cin >> N >> M;
	vector<long long int> v;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		high += num;
	}
	
	long long int answer = INT_MAX;
	while (low <= high)
	{
		long long int total = 0;
		long long int lecture = 1;
		long long int mid = (low + high) / 2;

		bool possible = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (mid < v[i])
			{
				low = mid + 1;
				possible = false;
				break;
			}

			if (total + v[i] > mid)
			{
				lecture++;
				total = v[i];
			}
			else
			{
				total += v[i];
			}
		}

		if (possible)
		{
			if (M >= lecture)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}

	cout << low;
}