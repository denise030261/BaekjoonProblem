#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int K;
	int dpA[46] = { 0, };
	int dpB[46] = { 0, };

	cin >> K;

	dpA[1] = 0;
	dpB[1] = 1;
	for (int i = 2; i <= K; i++)
	{
		dpA[i] = dpB[i - 1];
		dpB[i] = dpA[i - 1] + dpB[i - 1];
	}

	cout << dpA[K] << ' ' << dpB[K];
}