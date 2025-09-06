#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
    cin>>T;
    while(T!=0)
    {
        long long int A, B;
	cin >> A >> B;

	if (A > B)
	{
		long long int temp = A;
		A = B;
		B = temp;
	}

	for (int i = A; i >= 1; i--)
	{
		if (A % i == 0 && B % i == 0)
		{
			cout << (A / i) * (B / i) * i<<'\n';
			break;
		}
	}
        T--;
    }
}