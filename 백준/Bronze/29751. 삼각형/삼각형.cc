#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double H, W;
	cin >> H >> W;
	std::cout << std::fixed << std::setprecision(1) << (H * W) / 2;
}