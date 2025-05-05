#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int x;
	cin >> x;

	if (x % 3 == 0)
		cout << "S";
	else if (x % 3 == 1)
		cout << "U";
	else
		cout << "O";
}