#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<long long int> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = v.size() - 1;
	vector<long long int> answers(3, 0);
	long long int answer = 3e9;
	for (int i = 0; i < N - 2; i++) 
	{
		int left = i + 1;
		int right = N - 1;

		while (left < right) 
		{
			long long sum = v[i] + v[left] + v[right];

			if (abs(sum) < answer) 
			{
				answer = abs(sum);
				answers[0] = v[i];
				answers[1] = v[left];
				answers[2] = v[right];
			}

			if (sum < 0) 
			{
				left++;
			}
			else 
			{
				right--;
			}
		}
	}

	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << ' ';
	}
}