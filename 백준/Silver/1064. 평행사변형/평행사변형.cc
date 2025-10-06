#include <iostream>
#include <cmath>
#include <float.h>

using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(14);
	double x1, y1, x2, y2, x3, y3;
	double minDist = DBL_MAX;
	double maxDist = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1))
	{
		cout << -1;
		return 0;
	}

	double distAB = distance(x1, y1, x2, y2);
	double distAC = distance(x1, y1, x3, y3);
	double distBC = distance(x2, y2, x3, y3);

	minDist = min(minDist, 2 * (distAB + distAC));
	maxDist = max(maxDist, 2 * (distAB + distAC));

	minDist = min(minDist, 2 * (distBC + distAC));
	maxDist = max(maxDist, 2 * (distBC + distAC));

	minDist = min(minDist, 2 * (distAB + distBC));
	maxDist = max(maxDist, 2 * (distAB + distBC));
	
	cout << maxDist - minDist;
}