#include <iostream>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int A = 100;
	int B = 100;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a > b)
		{
			B -= a;
		}
		else if (a < b)
		{
			A -= b;
		}
	}

	cout << A << '\n' << B;
}
