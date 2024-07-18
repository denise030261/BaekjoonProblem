#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N,K;
	int tri[31][31] = { 0, };
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || j == i)
			{
				tri[i][j] = 1;
			}
			else
			{
				tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
			}
		}
	}

	cout << tri[N][K];
}