#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int T;
	long long int A[1001] = { 0, };
	long long int B[1001] = { 0, };
	vector<long long int> sumA;
	vector<long long int> sumB;
	long long int n, m;
	long long int answer = 0;

	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> B[i];
	}

	for (int i = 0; i < n; i++)
	{
		long long int sum = A[i];
		sumA.push_back(sum);
		for (int j=i + 1; j < n; j++)
		{
			sum += A[j];
			sumA.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		long long int sum = B[i];
		sumB.push_back(sum);
		for (int j = i + 1; j < m; j++)
		{
			sum += B[j];
			sumB.push_back(sum);
		}
	}
	
	sort(sumB.begin(), sumB.end());
	for (int i = 0; i < sumA.size(); i++)
	{
		long long int target = T - sumA[i];
		int low = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
		int high = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
	
		answer += high - low;
	}

	cout << answer;
}