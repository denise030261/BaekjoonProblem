#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int UR, TR, UO, TO;
	cin >> UR >> TR >> UO >> TO;

	cout << 56 * UR + 24 * TR + 14 * UO + 6 * TO;
}