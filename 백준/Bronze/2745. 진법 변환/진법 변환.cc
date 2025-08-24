#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int N;
	cin >> str >> N;

	long long answer = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int num = 0;
		if (str[i] >= 'A' && str[i] <= 'Z')
			num = str[i] - 'A' + 10;
		else
			num = str[i] - '0';
		answer += num*pow(N, str.length() - 1 - i);
	}
	cout << answer;
}