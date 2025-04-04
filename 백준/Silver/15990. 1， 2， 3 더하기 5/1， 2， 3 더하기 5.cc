#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    long long int answer = 0;
    long long int dp[100001][4] = { 0, };
    cin >> N;

    int num;

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
    for (int i = 4; i <= 100000; i++)
    {
        dp[i][1] = (dp[i - 1][3] + dp[i - 1][2]) % 1000000009;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        cout << (dp[num][1] + dp[num][2] + dp[num][3]) % 1000000009 << '\n';
    }
}