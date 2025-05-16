#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int A, B, C;
	cin >> A >> B >> C;

	if ((A + B + C) != 180)
	{
		cout << "Error";
	}
	else if (A == B && B == C)
	{
		cout << "Equilateral";
	}
	else if (A != B && A != C && B != C)
	{
		cout << "Scalene";
	}
	else
	{
		cout << "Isosceles";
	}
}