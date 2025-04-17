#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int Qs[100001] = { 0, };
	int Ns[101] = { 0, };
	int N, Q;
	int time = 0;

	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> Ns[i];
		for (int j = time; j < time+Ns[i]; j++)
		{
			Qs[j] = i;
		}

		time += Ns[i];
	}

	for (int i = 0; i < Q; i++)
	{
		int num;
		cin >> num;
		cout << Qs[num]<<'\n';
	}
}