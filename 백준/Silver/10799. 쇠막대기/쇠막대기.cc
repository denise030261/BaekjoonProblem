#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	vector<int> bounder;
	stack<int> left_bracket;
	int answer = 0;

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			left_bracket.push(i);
		}
		else if (str[i] == ')' && i - left_bracket.top() == 1)
		{
			bounder.push_back(left_bracket.top());
			left_bracket.pop();
		}
		else
		{
			int start = left_bracket.top();
			int end = i;
			left_bracket.pop();

			for (int j = 0; j < bounder.size(); j++)
			{
				if (start < bounder[j] && bounder[j] < end)
				{
					answer++;
				}
			}
			answer++;
		}
	}

	cout << answer;
}