#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double k,tugriks;
	cout.precision(2);

	cin >> k;
	tugriks = 25 + k * 0.01f;

	if (tugriks < 100)
	{
		cout << fixed << dec << 100.00;
	}
	else if (tugriks > 2000)
	{
		cout << fixed << dec <<2000.00;
	}
	else
	{
		
		cout << fixed<< dec <<tugriks;
	}
}