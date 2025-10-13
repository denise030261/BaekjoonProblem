#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		cout << str[0] - '0' + str[2] - '0' << '\n';
	}
}