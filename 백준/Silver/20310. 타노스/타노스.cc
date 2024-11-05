#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string S;
	int zero = 0;
	int one = 0;
	cin >> S;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '0')
		{
			zero++;
		}
		else if (S[i] == '1')
		{
			one++;
		}
	}

	zero /= 2; one /= 2;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '1')
		{
			S.erase(i, 1);
			i--;
			one--;
		}
		if (one ==0)
		{
			break;
		}
	}

	for (int i = S.length()-1; i >=0; i--)
	{
		if (S[i] == '0')
		{
			S.erase(i, 1);
			zero--;
		}
		if (zero ==0)
		{
			break;
		}
	}

	cout << S;
}