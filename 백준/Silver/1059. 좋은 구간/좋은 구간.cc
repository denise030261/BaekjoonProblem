#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int L,n;
	vector<int> S; 
	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int num;
		cin >> num;
		S.push_back(num);
	}
	cin >> n;

	sort(S.begin(), S.end());

	int start = -1, end = -1;
	for (int i = 0; i < S.size(); i++)
	{
		if ((S[i] >  n &&n>S[i-1]) && (S[i] > S[i - 1]))
		{
			start = S[i - 1] + 1;
			end = S[i] - 1;
			break;
		}
	}

	int answer = 0;
	for (int i = start; i <= n; i++)
	{
		for (int j = n; j <= end; j++)
		{
			if (i == j)
				continue;

			answer++;
		}
	}
	cout << answer;
}