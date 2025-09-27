#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

	int answer = 0;
	for (int i = A; i < B; i++)
	{
		if (i < 0)
		{
			answer += C;
		}
		else if (i == 0)
		{
			answer += D;
			answer += E;
		}
		else
		{
			answer += E;
		}
	}

	cout << answer;
}