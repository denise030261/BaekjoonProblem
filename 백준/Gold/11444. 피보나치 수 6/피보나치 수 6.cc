#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;
const long long MOD = 1000000007;

matrix multiply(const matrix& a, const matrix& b)
{
    matrix c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            for (int k = 0; k < 2; k++) 
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}

matrix power(matrix a, long long n)
{
    matrix res(2, vector<long long>(2));
    res[0][0] = res[1][1] = 1;

    while (n > 0) 
    {
        if (n % 2 == 1) 
        {
            res = multiply(res, a);
        }
        a = multiply(a, a);
        n /= 2;
    }

    return res;
}


int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n;
    cin >> n;

    matrix base(2, vector<long long>(2));
    base[0][0] = 1; base[0][1] = 1; base[1][0] = 1; base[1][1] = 0;

    matrix result = power(base, n);
    cout << result[0][1];

    return 0;
}