#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	long long int N, M;
	vector<long long int> v;
	cin >> N >> M;
	long long int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = v.size() - 1; j >= 0; j--)
		{
			if (v[i] + v[j] == M)
			{
				answer++;
			}
			else if(v[i] + v[j] < M)
			{
				break;
			}
		}
	}

	cout << answer/2;
}