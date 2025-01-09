#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int X, N;
	int sum = 0;
	cin >> X >> N;
	
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}

	if (sum == X)
		cout << "Yes";
	else
		cout << "No";
}