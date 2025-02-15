#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int L;
	cin >> L;
	if (L % 5 == 0)
		cout << L / 5;
	else
		cout << L / 5 + 1;
}