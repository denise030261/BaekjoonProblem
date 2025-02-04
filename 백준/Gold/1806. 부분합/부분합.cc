#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, S;
	int arr[100001] = { 0, };
	cin >> N >> S;

	int start = 0;
	int end = 0;
	int answer = INT_MAX;
	int sum = 0;
	int length = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while (start <= end && end<=N)
	{
		if(sum>=S)
			answer = min(length, answer);

		if (sum < S)
		{
			sum += arr[end];
			length++;
			end++;
		}
		else
		{		
			sum -= arr[start];
			start++;
			length--;
		}
	}

	if (answer == INT_MAX)
		cout << 0;
	else
		cout << answer;
}