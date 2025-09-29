#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	
	int start_sum=0, end_sum = 0;
	int start = 0, end = 0;
	int answer = 0;
	while (start<=end && end<=N)
	{
		int num = end_sum - start_sum;
		if (num < N)
		{
			end++;
			end_sum += end;
		}
		else if (num > N)
		{
			start++;
			start_sum += start;
		}
		else
		{
			answer++;
			end++;
			end_sum += end;
		}
	}

	cout << answer;
}