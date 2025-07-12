#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		string str;
		getline(cin, str);

		if (str == "END")
			break;

		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
}