#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	 int a1, a0, c, n0;
	cin >> a1 >> a0;
	cin >> c;
	cin >> n0;

	 int result = a1 * n0 + a0;
	if (result <= c * n0 && a1<=c)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}