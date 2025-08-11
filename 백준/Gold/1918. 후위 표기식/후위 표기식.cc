#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	stack<char> s;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			if (s.empty())
			{
				s.push(str[i]);
				continue;
			}
			else if (s.top() == '*' || s.top() == '/' )
			{
				while (!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-')
				{
					cout << s.top();
					s.pop();
				}
			}
			s.push(str[i]);
		}
		else if(str[i] == '+' || str[i]=='-')
		{
			if (s.empty())
			{
				s.push(str[i]);
				continue;
			}
			else if (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')
			{
				while (!s.empty() && s.top()!='(')
				{
					cout << s.top();
					s.pop();
				}
			}
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (s.top()!='(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			cout << str[i];
		}
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}