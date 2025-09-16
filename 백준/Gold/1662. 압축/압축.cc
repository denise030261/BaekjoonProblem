#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	stack<int> st;
	cin >> str;

	long int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ')')
		{
			if (i + 1 < str.length())
			{
				if (str[i + 1] == '(' || str[i] == '(')
				{
					if (str[i] >= '0' && str[i] <= '9')
					{
						st.push(str[i]-'0');
					}
					else
					{
						st.push(-1);
					}
					continue;
				}
			}
			st.push(1);
		}
		else
		{
			long int num = 0;
			while (st.top() != -1)
			{
				//cout << st.top()<<" : " << st.top() << ' ';
				num += st.top();
				st.pop();
			}
			st.pop();
			//cout << st.top() << ' ';
			num *= st.top();
			st.pop();
			st.push(num);
			//cout << num << '\n';
		}
	}

	while (!st.empty())
	{
		sum+=st.top();
		st.pop();
	}

	cout << sum;
}