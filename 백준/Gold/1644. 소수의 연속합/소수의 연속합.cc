#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long int N;
	vector<long int> v;
	cin >> N;

	bool composites[4000001] = { 0, };
	composites[1] = true;
	v.push_back(0);
	for (long int i = 2; i <= 4000000; i++)
	{
		for (long int j = 2; i*j <= 4000000;j++)
		{
			if(!composites[i * j])
				composites[i * j] = true;

		}
	}

	long int sum = 0;
	for (long int i = 2; i <= 4000000; i++)
	{
		if (!composites[i])
		{
			sum += i;
			v.push_back(sum);
		}
	}

	int answer = 0;
	int start = 0;
	int end = 0;

	while (start <= end && end<v.size())
	{
		if (v[end] - v[start] > N)
		{
			start++;
		}
		else if (v[end] - v[start] < N)
		{
			end++;
		}
		else
		{
			answer++;
			end++;
		}
	}

	cout << answer;
}