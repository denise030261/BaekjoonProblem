#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int N;
	long long int shirtSet = 0;
	long long int shirt = 0;
	long long int penSet = 0;
	vector<long long int> v;
	cin >> N;

	long long int num;
	for (int i = 0; i < 6; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	cin >> shirtSet >> penSet;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % shirtSet == 0)
		{
			shirt += (v[i] / shirtSet);
		}
		else
		{
			shirt += (v[i] / shirtSet) + 1;
		}
	}

	cout << shirt << '\n';
	cout << N / penSet << ' ' << N % penSet;
}