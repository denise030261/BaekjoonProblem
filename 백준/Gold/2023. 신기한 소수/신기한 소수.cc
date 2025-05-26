#include <iostream>
#include <string>

using namespace std;

int N;

bool isPrime(int num)
{
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

void dfs(int length, string result)
{
	if (length == N)
	{
		cout << result << '\n';
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (length == 0 && i == 1)
			continue;

		string change = result;
		string str = to_string(i);
		change += str;

		if (isPrime(stoi(change)))
		{
			dfs(length + 1, change);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	dfs(0, "");
}