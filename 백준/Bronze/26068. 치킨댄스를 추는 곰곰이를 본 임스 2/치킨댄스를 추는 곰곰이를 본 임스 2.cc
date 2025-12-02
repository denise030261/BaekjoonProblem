#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		str.erase(0, 2);

		if (stoi(str) <= 90)
		{
			answer++;
		}
	}

	cout << answer;
}