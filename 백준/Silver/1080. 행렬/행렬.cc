#include <iostream>

using namespace std;

bool A[50][50] = { 0, }; 
bool B[50][50] = { 0, }; // answer

void ChangeMatrix(int row, int col)
{
	for (int i = row; i < row+3; i++)
	{
		for (int j = col; j < col+3; j++)
		{
			A[i][j] = !A[i][j];
		}
	}
}

bool AreMatricesEqual(int N, int M) 
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			if (A[i][j] != B[i][j]) 
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int answer = 0;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			A[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			B[i][j] = str[j] - '0';
		}
	}

	if (N < 3 || M < 3)
	{
		if (AreMatricesEqual(N, M))
			cout << 0;
		else 
			cout << -1;

		return 0;
	}

	for (int i = 0; i <= N - 3; i++) 
	{
		for (int j = 0; j <= M - 3; j++) 
		{
			if (A[i][j] != B[i][j]) 
			{
				ChangeMatrix(i, j);
				answer++;
			}
		}
	}

	if (AreMatricesEqual(N, M))
		cout << answer;
	else 
		cout << -1;
}