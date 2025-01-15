#include <iostream>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int hambuger = INT_MAX;
	int drink = INT_MAX;

	int num;
	for (int i = 0; i < 3; i++)
	{
		cin >> num;
		hambuger = min(num, hambuger);
	}

	for (int i = 0; i < 2; i++)
	{
		cin >> num;
		drink = min(num, drink);
	}

	cout << hambuger + drink - 50;
}