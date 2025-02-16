#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int egg = 0;
	long long int answer = 0;

	cin >> N >> M;
	vector<long long int> v;
	
	int input;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		int num;
		if (N >= (v.size() - i))
			num = v[i] * (v.size() - i);
		else
			num = v[i] * N;

		if (answer < num)
		{
			egg = v[i];
			answer = num;
		}
	}

	cout << egg << ' ' << answer;
}