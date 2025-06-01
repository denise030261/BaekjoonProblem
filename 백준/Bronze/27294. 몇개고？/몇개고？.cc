#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, S;
	cin >> T >> S;

	if (S == 1 || (T <= 11 || T > 16))
		cout << 280;
	else
		cout << 320;
}