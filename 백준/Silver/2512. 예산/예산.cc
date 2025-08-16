#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int N, M;
	vector<long long int> v;
	cin >> N;
	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		long long int num;
		cin >> num;
		v.push_back(num);
		sum += num;
	}
	cin >> M;
	sort(v.begin(), v.end());
	if (sum <= M)
	{
		cout << v[v.size() - 1];
		return 0;
	}


	long long int answer = 0;
	long long int spare = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] * (N - i) < M)
		{
			M -= v[i];
		}
		else
		{
			answer = v[i];
			spare = i;
			break;
		}
	}

	for (long long int i = answer; i >= 0; i--)
	{
		if (i * (N - spare) <= M)
		{
			answer = i;
			break;
		}
	}

	cout << answer;
}