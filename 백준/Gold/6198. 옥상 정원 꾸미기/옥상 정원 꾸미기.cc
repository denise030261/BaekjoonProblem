#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<int> v;
	stack<int> s;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	s.push(0);
	long long int answer = 0;
	for (int i = 1; i < N; i++)
	{
		int top_index = 0;
		while (!s.empty() &&  v[s.top()] <= v[i])
		{
			top_index = s.top();
			s.pop();

			answer += i - top_index - 1;
		}

		s.push(i);
	}

	while (!s.empty())
	{
		answer += N - 1 - s.top();
		s.pop();
	}

	cout << answer;
}