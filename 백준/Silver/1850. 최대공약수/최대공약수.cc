#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

long long int gcd(long long a, long long b)
{
    long long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long A, B;
    long long answer = 1;
    cin >> A >> B;

    if (B > A)
    {
        swap(A, B);
    }

    answer = gcd(A, B);

    for (long long i = 0; i < answer; i++)
    {
        cout << 1;
    }
}