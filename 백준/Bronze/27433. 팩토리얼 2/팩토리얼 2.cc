#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	long long int answer = 1;

	cin >> N;
	for (int i = N; i >= 1; i--)
	{
		answer *= i;
	}

	cout << answer;
}