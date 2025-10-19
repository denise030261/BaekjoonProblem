#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool read = true;

	for (int i = 0; i < 8; i++)
	{
		int num;
		cin >> num;
		if (num > 1)
		{
			read = false;
		}
	}

	if (read)
	{
		cout << "S";
	}
	else
	{
		cout << "F";
	}
}