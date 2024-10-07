#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int alkali = 0;
	int acid = 0;
	vector<long long int> v;

	cin >> N;

	long long int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = v.size() - 1;
	int sum = 2000000001;
	int answer= 2000000001;
	while (start < end)
	{
		sum = v[start] + v[end];
		if (abs(answer) > abs(sum))
		{
			answer = v[start] + v[end];
			alkali = v[start];
			acid = v[end];
		}

		if (sum == 0)
		{
			break;
		}
		else if (sum < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << alkali << ' ' << acid;
}