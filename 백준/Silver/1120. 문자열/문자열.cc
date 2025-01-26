#include <iostream>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string A, B;
	cin >> A >> B;

	int answer = INT_MAX;
	for (int i = 0; i < B.length()-A.length()+1; i++)
	{
		int sum = 0;
		for (int j = 0; j < A.length(); j++)
		{
			if (B[i + j] != A[j])
				sum++;
		}
		answer = min(answer, sum);
	}

	cout << answer;
}