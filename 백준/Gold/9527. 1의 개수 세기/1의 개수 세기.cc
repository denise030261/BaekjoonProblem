#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
long long int arr[55];

long long int countBits(long long num)
{
	long long result = num & 1;
	for (int i = 54; i > 0; i--)
	{
		if (num & (1LL << i))
		{
			result += arr[i - 1] + (num - (1LL << i) + 1);
			num -= 1LL << i;
		}
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int A, B;
	cin >> A >> B;

	arr[0] = 1;
	for (long long int i = 1; i < 55; i++)
	{
		arr[i] = arr[i - 1] * 2 + (1LL << i);
	}

	cout << countBits(B) - countBits(A - 1);
}