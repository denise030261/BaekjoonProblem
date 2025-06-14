#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		int a, b;
		cin >> str;
		cin >> a >> b;
		str.erase(a, b-a);

		cout << str << '\n';
	}
}