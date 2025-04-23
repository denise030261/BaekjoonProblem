#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int Factorial[11] = { 0, };
	int T;
	
	int num = 1;
	for (int i = 1; i <= 10; i++)
	{
		num *= i;
		Factorial[i] = num;
	}

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int input;
		cin >> input;
		cout << Factorial[input]%10<<'\n';
	}
}