#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int arr[100] = { 0, };
	int ring = 0;

	cin >> ring;
	for (int i = 1; i < N; i++)
	{
		cin >> arr[i - 1];
	}

	for (int i = 0; i < N-1; i++)
	{
		int div = gcd(ring, arr[i]);
		cout << ring / div << "/" << arr[i] / div << '\n';
	}
}