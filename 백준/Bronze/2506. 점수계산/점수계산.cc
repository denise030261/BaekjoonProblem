#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int answer = 0;
	vector<int> v;
	cin >> N;
	
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i] == 0)
		{
			sum = 0;
		}
		else
		{
			sum++;
			answer += sum;
		}
	}

	cout << answer;
}