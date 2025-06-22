#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str1, str2;
	int answer = 0;
	getline(cin, str1);
	getline(cin, str2);

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == str2[0])
		{
			bool correct = true;
			for (int j = 0; j < str2.length(); j++)
			{
				if (str1[i + j] != str2[j])
				{
					correct = false;
					break;
				}
			}

			if (correct)
			{
				answer++;
				i += str2.length() - 1;
			}
		}
	}

	cout << answer;
}