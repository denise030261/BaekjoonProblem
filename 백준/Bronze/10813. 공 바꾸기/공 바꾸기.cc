#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, N;
	int balls[101] = { 0, };
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		balls[i] = i;
	
	for (int i = 0; i < M; i++)
	{
		int a, b, temp;
		int ballA, ballB;
		cin >> a >> b;
		ballA = balls[a];
		ballB = balls[b];
		balls[a] = ballB;
		balls[b] = ballA;
	}

	for (int i = 1; i <= N; i++)
	{
		cout << balls[i] << ' ';
	}
}