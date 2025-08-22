#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;
int N, r, c;
int ans = 0;

void div(int x, int y, int size)
{
	if (c == x && r == y)
	{
		cout << ans;
		return;
	}

	else if (c < x + size && r < y + size && c >= x && r >= y)
	{
		div(x, y, size / 2);
		div(x + size / 2, y, size / 2);
		div(x, y + size / 2, size / 2);
		div(x + size / 2, y + size / 2, size / 2);
	}

	else
		ans += size * size;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	cin >> N >> r >> c;
	div(0, 0, pow(2, N));
}