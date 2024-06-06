#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int zero = 0;
	int one = 0;
	int pre = 0;

	string str;

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0)
		{
			pre = str[i] - '0';
			if (str[i] - '0' == 0)
			{
				zero++;
			}
			else
			{
				one++;
			}
		}
		else
		{
			if (pre != str[i] - '0')
			{
				pre = str[i] - '0';
				if (pre == 0)
				{
					zero++;
				}
				else
				{
					one++;
				}
			}
		}
	}

	cout << min(one, zero);
}