#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char c;
	cin >> c;
	if (c == 'n' || c == 'N')
	{
		cout << "Naver D2";
	}
	else
	{
		cout << "Naver Whale";
	}
}