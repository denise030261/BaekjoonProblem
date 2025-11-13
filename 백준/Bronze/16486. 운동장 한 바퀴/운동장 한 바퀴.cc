#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double d1, d2;
	cin >> d1 >> d2;
	cout << fixed;
	cout.precision(6);
	cout << d1 * 2 + 2 * d2 * 3.141592;
}