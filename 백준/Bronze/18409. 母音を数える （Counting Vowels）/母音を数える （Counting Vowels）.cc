#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string str;
	cin >> N >> str;
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (str[i] == 'a' || str[i] == 'i' || str[i] == 'o' || str[i] == 'e' || str[i] == 'u')
			answer++;
	}

	cout << answer;
}