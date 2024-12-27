#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int add = 0;
	int pos = str.length();

	bool bCheck = true;
	while (1)
	{
		int start = 0;
		int end = str.length() - 1;

		bCheck = true;
		while (start < end)
		{
			if (str[start] != str[end])
			{
				bCheck = false;
				break;
			}

			start++;
			end--;
		}

		if (bCheck)
			break;

		str.insert(str.begin() + pos, str[add++]);
	}

	cout << str.length();
}