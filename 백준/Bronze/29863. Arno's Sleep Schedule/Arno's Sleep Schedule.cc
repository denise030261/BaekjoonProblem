#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sleep, awake;
	cin >> sleep >> awake;
	if (sleep > awake)
		awake += 24;
	cout << awake - sleep;
}