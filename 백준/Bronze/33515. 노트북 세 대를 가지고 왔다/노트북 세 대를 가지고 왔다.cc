#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T1, T2;
	cin >> T1 >> T2;
	cout << min(T1, T2);
}