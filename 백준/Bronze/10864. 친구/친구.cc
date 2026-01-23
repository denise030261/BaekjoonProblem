#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> v(N+1, 0);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a]++;
		v[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		cout << v[i] << '\n';
	}
}