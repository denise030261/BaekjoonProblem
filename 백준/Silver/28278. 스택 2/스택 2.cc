#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	stack<int> s;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int order;
		cin >> order;
		if (order == 1)
		{
			int num;
			cin >> num;
			s.push(num);
		}
		else if (order == 2)
		{
			if (!s.empty())
			{
				cout << s.top() << '\n';
				s.pop();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (order == 3)
		{
			cout << s.size() << '\n';
		}
		else if (order == 4)
		{
			cout << s.empty() << '\n';
		}
		else
		{
			if (!s.empty())
			{
				cout << s.top() << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
	}
}