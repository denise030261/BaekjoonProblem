#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			cout << ' ';
		}
		for (int j = i; j >= 0; j--)
		{
			cout << '*';
		}
		cout << '\n';
	}

	for (int i = 0; i < N; i++)
		cout << '*';
	cout << '\n';

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			cout << ' ';
		}
		for (int j = i+1; j < N; j++)
		{
			cout << '*';
		}
		cout << '\n';
	}
}