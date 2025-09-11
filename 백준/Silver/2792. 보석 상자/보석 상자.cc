#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	vector<int> v;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	int answer = 0; 
	int left = 1, right = 1000000000;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		long long int sum = 0;
		for (int i = 0; i < M; i++)
		{
			sum += (v[i] + mid - 1) / mid;
		}

		if (sum <= N) 
		{ 
			answer = mid;       
			right = mid - 1;    
		}
		else 
		{ 
			left = mid + 1;     
		}
	}

	cout << answer;
}