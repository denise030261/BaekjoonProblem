#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int Min = 0;
	int Man = 0;

	for (int i = 0; i < 4; i++)
	{
		int num;
		cin >> num;
		Min += num;
	}
	for (int i = 0; i < 4; i++)
	{
		int num;
		cin >> num;
		Man += num;
	}

	cout << max(Min, Man);
}