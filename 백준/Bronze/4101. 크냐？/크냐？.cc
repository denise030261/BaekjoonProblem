#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	bool root = true;
	do {
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			break;
		}
		else
		{
			if (a > b)
			{
				cout << "Yes";
			}
			else
			{
				cout << "No";
			}
			cout << '\n';
		}
	} while (root);
}