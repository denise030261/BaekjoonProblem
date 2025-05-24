#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int A[100][100] = { 0, };
	long long int B[100][100] = { 0, };
	int A_N, A_M;

	cin >> A_N >> A_M;
	for (int i = 0; i < A_N; i++)
	{
		for (int j = 0; j < A_M; j++)
		{
			cin >> A[i][j];
		}
	}

	int B_N, B_M;
	cin >> B_N >> B_M;
	for (int i = 0; i < B_N; i++)
	{
		for (int j = 0; j < B_M; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < A_N; i++)
	{
		for (int j = 0; j < B_M; j++)
		{
			long long int sum = 0;
			for (int k = 0; k < B_N; k++)
			{
				sum += A[i][k] * B[k][j];
			}
			cout << sum << ' ';
		}
		cout << '\n';
	}
}