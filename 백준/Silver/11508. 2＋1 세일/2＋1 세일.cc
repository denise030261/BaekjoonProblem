#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v;
	int N;
	int answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int count = 0;
	for (int i = N-1; i >=0; i--)
	{
		if (count / 3 == N/3)
		{
			if (N % 3 == 0)
			{
				if (count % 3 == 1 || count % 3 == 2)
				{
					answer += v[i];
				}
			}
			else
			{
				    answer += v[i];
			}
		}
		else
		{
			if (count % 3 == 1 || count % 3 == 0)
			{
				answer += v[i];
			}
		}

		count++;
	}

	cout << answer;
}