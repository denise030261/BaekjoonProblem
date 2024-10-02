#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int answer = 0;
	int N;
	vector<int> dist;
	vector<int> oil;
	
	cin >> N;
	int num = 0;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> num;
		dist.push_back(num);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		oil.push_back(num);
	}

	int minOil = 987654321;
	for (int i = 0; i < N-1; i++)
	{
		minOil = min(minOil, oil[i]);
		answer += minOil * dist[i];
	}

	cout << answer;
}