#include <iostream>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;

	cout << m * k + m;
}