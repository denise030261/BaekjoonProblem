#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int size = 0;
	int k, n = 0;
	cin >> size;
	while (size != 0)
	{
		cin >> k;
		cin >> n;
		int people[15][15] = { 0, };
		for (int i = 1;i <= n;i++)
			people[0][i] = i;//0층 1호~n호
		for (int i = 1;i <= k;i++)
			for (int j = 1;j <= n;j++)
				for (int p = 1;p <= j;p++)
					people[i][j] += people[i - 1][p];
		cout << people[k][n] << endl;
		size--;
	}
}