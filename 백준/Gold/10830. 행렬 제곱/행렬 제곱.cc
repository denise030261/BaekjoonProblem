#include <iostream>

using namespace std;

long long int N, B;
long long int A[6][6];
long long int answer[6][6];
long long int temp[6][6];

void Matrix(long long int mat1[6][6], long long int mat2[6][6])
{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				temp[i][j] = 0;
				for (int k = 1; k <= N; k++)
				{
					temp[i][j] += mat1[i][k] * mat2[k][j];
				}
				temp[i][j] %=  1000;
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				mat1[i][j] = temp[i][j];
			}
		}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> B;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
		answer[i][i] = 1;
	}

	while (B)
	{
		if (B % 2 == 1)
		{
			Matrix(answer, A);
		}
		Matrix(A, A);
		B /= 2;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << answer[i][j]<<' ';
		}
		cout << '\n';
	}
}