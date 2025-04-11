#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		int sum = 0;
		for (int j = 1; j <= num; j += 2) {
			sum += j;
		}
		cout << sum << '\n';
	}
}