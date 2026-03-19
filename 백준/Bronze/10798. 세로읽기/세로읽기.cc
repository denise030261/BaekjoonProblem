#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<string> v;
	int length = 0;

	for (int i = 0; i < 5; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
		length = max(length, (int)str.length());
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (v[j].length() < i || v[j][i] == '\0')
				continue;

			cout << v[j][i];
		}
	}
}