#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

vector<int> v;
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
		//cout << i << " : ";

		string change = result;
		string str = to_string(i);
		change += str;

		//cout << change << '\n';

		if (isPrime(stoi(change)))
		{
			//cout << "change is " << change << '\n';
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