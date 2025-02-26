#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;
	int Korean = (A % C == 0 ? A / C : A / C + 1);
	int Math = (B % D == 0 ? B / D : B / D + 1);
	cout << L - (Korean >= Math ? Korean : Math);
}