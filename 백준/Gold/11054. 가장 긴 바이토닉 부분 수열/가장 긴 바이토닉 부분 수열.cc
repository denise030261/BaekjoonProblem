#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int A;
	int answer = 0;
	int arrA[1000];
	int arrB[1000];
	int arrC[1000];

	cin >> A;
	for (int i = 0; i < A; i++)
	{
		cin >> arrA[i];
	}

	for (int i = 0; i < A; i++)
	{
		arrB[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arrA[i] > arrA[j])
			{
				arrB[i] = max(arrB[i], arrB[j] + 1);
			}
		}
	}

	for (int i = A-1; i >= 0; i--)
	{
		arrC[i] = 1;
		for (int j = A-1; j > i; j--)
		{
			if (arrA[i] > arrA[j])
			{
				arrC[i] = max(arrC[i], arrC[j] + 1);
			}
		}
	}

	for (int i = 0; i < A; i++)
	{
		int sum = arrB[i] + arrC[i];
		if (sum > answer)
		{
			answer = sum;
		}
	}

	cout << answer - 1;
}