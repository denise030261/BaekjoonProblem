#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num = 0;
	string str;
	int A = 0, B = 0;
	cin >> num;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'A')
			A++;
		else
			B++;
	}

	if (A > B)
		cout << "A";
	else if (A < B)
		cout << "B";
	else
		cout << "Tie";
}