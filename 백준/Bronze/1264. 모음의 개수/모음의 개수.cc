#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;

	while (1)
	{
		getline(cin, str);
		if (str == "#")
			break;

		int answer = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
				str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
				answer++;
		}

		cout << answer << '\n';
	}
}