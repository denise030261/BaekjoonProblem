#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int between = 0;
	int Y, M;
	cin >> Y >> M;
	cout << M + (M - Y);
}