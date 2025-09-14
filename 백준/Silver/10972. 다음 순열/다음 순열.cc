#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<int> v;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	if (next_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < N; i++)
		{
			cout << v[i] << ' ';
		}
	}
	else
	{
		cout << -1;
	}
}