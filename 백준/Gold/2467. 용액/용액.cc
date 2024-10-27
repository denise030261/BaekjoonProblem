#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	long long int num = 0;
	long long int sum = 3000000000;
	long long int acid = 0;
	long long int alkali = 0;
	vector<long long int> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	long long int front = 0;
	long long int back = v.size() - 1;
	sort(v.begin(), v.end());

	while (front < back)
	{
		if (sum > abs(v[front] + v[back]))
		{
			sum = abs(abs(v[front] + v[back]));
			alkali = v[front];
			acid = v[back];
		}

		if (v[front] + v[back] > 0)
		{
			back--;
		}
		else if (v[front] + v[back] < 0)
		{
			front++;
		}
		else if (v[front] + v[back] == 0)
		{
			break;
		}
	}

	cout << alkali << ' ' << acid;
}
