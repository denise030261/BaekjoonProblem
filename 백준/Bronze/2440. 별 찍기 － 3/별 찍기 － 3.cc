#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	string str = "";
	for (int i = 0; i < N; i++)
	{
		str += '*';
	}

	for (int i = 0; i < N; i++)
	{
		cout << str << '\n';
		str.pop_back();
	}
}