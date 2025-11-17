#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		string str;
		cin >> str;

		if (str == "0")
		{
			break;
		}

		int sum = 0;

		for (int i = 0; i < str.length(); i++)
		{
			sum++;

			if (str[i] == '1')
			{
				sum += 2;
			}
			else if (str[i] == '0')
			{
				sum += 4;
			}
			else
			{
				sum += 3;
			}
		}
		sum++;

		cout << sum << '\n';
	}
}