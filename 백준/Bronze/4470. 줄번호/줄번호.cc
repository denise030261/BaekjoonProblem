#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int N;
	cin >> N;
	getline(cin, str);
	for (int i = 1; i <= N; i++)
	{
		getline(cin, str);
		cout << i << ". " << str << '\n';
	}

}