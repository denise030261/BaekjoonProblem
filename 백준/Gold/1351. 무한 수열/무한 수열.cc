#include <iostream>
#include <map>

using namespace std;

long int N, P, Q;
map<long int, long int> m;

long int dfs(long int num)
{
	if (num == 0)
	{
		return 1;
	}

	long int divP = num / P;
	long int divQ = num / Q;

	return (m[divP] != 0 ? m[divP] : m[divP]=dfs(divP)) + (m[divQ] != 0 ? m[divQ] : m[divQ]= dfs(divQ));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P >> Q;

	cout << dfs(N);
}