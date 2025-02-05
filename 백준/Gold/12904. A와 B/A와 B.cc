#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string S, T;
	cin >> S >> T;

	int index = T.length() - 1;
	while (S.length() != T.length())
	{
		if (T[index] == 'A')
			T.erase(T.begin() + index);
		else
		{
			T.erase(T.begin() + index);
			reverse(T.begin(), T.end());
		}

		index--;
	}
	
	if (S == T)
		cout << 1;
	else
		cout << 0;
}