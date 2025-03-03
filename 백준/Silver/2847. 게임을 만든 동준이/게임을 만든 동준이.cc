#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int answer = 0;
	vector<int> v;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = v.size() - 2; i >= 0; i--)
	{
		int previous = v[i + 1] - 1;
		if (v[i] >= previous)
		{
			answer += v[i] - previous;
			v[i] = previous;
		}
	}

	cout << answer;
}