#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, F;
	while (1)
	{
		cin >> M >> F;
		if (M == 0 && F == 0)
			break;
		cout << M + F << '\n';
	}
}