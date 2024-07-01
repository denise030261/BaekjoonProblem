#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;

	if (str1.length() < str2.length())
	{
		cout << "no";
	}
	else
	{
		cout << "go";
	}
}