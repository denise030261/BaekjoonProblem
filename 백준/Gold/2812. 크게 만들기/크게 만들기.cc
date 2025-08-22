#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	stack<int> st;
	string str;
	cin >> N >> M;
	cin >> str;
	
	for (int i = 0; i<str.length(); i++)
	{
		int num = str[i] - '0';
		
		if (st.empty() || M == 0 || (!st.empty() && st.top()>=num))
		{
			st.push(num);
		}
		else if (st.top() < num && !st.empty())
		{
			while(!st.empty() && M!=0)
			{
				if (st.top() < num)
				{
					st.pop();
					M--;
				}
				else
				{
					break;
				}
			}
			st.push(num);
		}
	}

	while (M != 0)
	{
		st.pop();
		M--;
	}

	string answer = "";
	while (!st.empty())
	{
		answer += st.top() + '0';
		st.pop();
	}

	reverse(answer.begin(), answer.end());

	if (answer == "")
	{
		cout << 0;
	}
	else
	{
		cout << answer;
	}
}
