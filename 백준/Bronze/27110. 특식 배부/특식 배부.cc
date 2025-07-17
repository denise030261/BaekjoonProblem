#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, A, B, C;

	cin >> N;
	cin >> A >> B >> C;

	cout << (A >= N ? N : A)+ (B >= N ? N : B)+ (C >= N ? N : C);
}