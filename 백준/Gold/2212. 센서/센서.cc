#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = 0;
	int N, K;
	vector<int> v;
	vector<int> compares;
	cin >> N >> K;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N - 1; i++)
	{
		compares.push_back(v[i + 1] - v[i]);
	}
	sort(compares.begin(), compares.end());

	for (int i = 0; i < N-K; i++)
	{
		answer += compares[i];
	}

	cout << answer;
}