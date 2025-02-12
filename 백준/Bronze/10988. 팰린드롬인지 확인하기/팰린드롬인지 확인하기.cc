#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	string reverse_str;
	cin >> str;
	reverse_str = str;
	reverse(reverse_str.begin(), reverse_str.end());

	if (str == reverse_str)
		cout << 1;
	else
		cout << 0;
}