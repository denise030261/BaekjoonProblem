#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

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

	sort(v.begin(), v.end(), compare);

	long long int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int tip = v[i] - (i);
		if (tip > 0)
			answer += tip;
	}

	cout << answer;
}