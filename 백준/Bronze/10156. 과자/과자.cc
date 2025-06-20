#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K, N, M;
	cin >> K >> N >> M;

	if (K * N > M)
	{
		cout << abs(K * N - M);
	}
	else
	{
		cout << 0;
	}
}