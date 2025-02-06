#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string answer = "";
	cin >> N;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (answer == "")
			answer = str;

		for (int j = 0; j < str.length(); j++)
		{
			if (answer[j] != str[j])
				answer[j] = '?';
		}
	}

	cout << answer;
}
