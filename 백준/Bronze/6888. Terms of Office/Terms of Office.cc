#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int X, Y;
	cin >> X >> Y;
	
	int year = X;
	cout << "All positions change in year " << year << '\n';
	year += 60;
	while (year<=Y)
	{
		cout << "All positions change in year " << year << '\n';
		year += 60;
	}
}