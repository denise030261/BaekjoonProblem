#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, d, N; // a는 성체 되는 날, b는 새로운 객체 만들지 않음, d는 죽음, N은 마무리 날
    cin >> a >> b >> d >> N;
    
    long int dp[1000001] = { 0, };
    long int sum[1000001] = { 0, };

    dp[0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= a - 1; i++)
    {
        dp[i] = 0;
        sum[i] = 1;
    }
    for (int i = a; i <= N; i++)
    {
        if (i - b < 0)
        {
            dp[i] = sum[i - a] % 1000;
        }
        else
        {
            dp[i] = (sum[i - a] - sum[i - b]+1000)%1000;
        }
        sum[i] = (sum[i - 1] + dp[i]) % 1000;
    }

    if (N - d < 0)
    {
        cout << sum[N] % 1000;
    }
    else
    {
        cout << (sum[N] - sum[N - d] + 1000) % 1000;
    }
}