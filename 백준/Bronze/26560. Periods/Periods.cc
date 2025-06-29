#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string s;
		getline(cin, s);
		
		if (!s.empty() && s.back() != '.')
			s += '.';

		cout << s << '\n';
	}
}