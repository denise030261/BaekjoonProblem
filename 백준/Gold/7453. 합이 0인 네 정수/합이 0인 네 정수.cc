#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	long long int answer = 0;
	long long int arr[4000][4] = { 0, };
	vector<long long int> A;
	vector<long long int> B;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long int sum = arr[i][0] + arr[j][1];
			A.push_back(sum);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long int sum = arr[i][2] + arr[j][3];
			B.push_back(sum);
		}
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int start = 0;
	int end = 0;
	while (0<=start && start<A.size() && 0 <= end && end < B.size())
	{
		if (A[start] + B[end] == 0)
		{
			long long int staCount = 1;
			long long int endCount = 1;

			for (int i = 1; i+ start < n*n; i++)
			{
				if (A[start + i] == A[start])
				{
					staCount++;
				}
				else
				{
					break;
				}
			}
			for (int j = 1; j+end < n * n; j++)
			{
				if (B[end + j] == B[end])
				{
					endCount++;
				}
				else
				{
					break;
				}
			}
			answer+=staCount*endCount;
			start+= staCount;
			end += endCount;
		}
		else if (A[start] + B[end] < 0)
		{
			start++;
		}
		else
		{
			end++;
		}
	}

	cout << answer;
}