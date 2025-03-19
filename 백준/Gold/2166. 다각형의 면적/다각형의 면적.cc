#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<pair<double, double>> v;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += v[i].first * v[i + 1 < N ? i + 1 : 0].second;
		sum -= v[i + 1 < N ? i + 1 : 0].first * v[i].second;
	}
	
	sum /= 2.0;
	sum = abs(sum);

	cout << fixed;
	cout.precision(1);
	cout << sum;
}