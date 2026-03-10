#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long int combination[53][53] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    if (N >= 1 && N <= 3)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i <= 52; i++)
    {
        combination[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % 10007;
        }
    }

    long long int answer = 0;
    for (int k = 1; 4 * k <= N; k++)
    {
        long long int temp = (combination[13][k] * combination[52 - 4 * k][N - 4 * k])%10007;
        if (k % 2 == 1)
        {
            answer = (answer + temp) % 10007;
        }
        else
        {
            answer = (answer - temp + 10007) % 10007;
        }
    }

    cout << answer;
}