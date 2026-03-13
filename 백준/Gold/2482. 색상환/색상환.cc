#include <iostream>
#define DIV 1000000003

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    int dp[1001][1001] = {0,}; // i개의 색깔 중 j개를 선택하는 방법의 수
    cin >> N >> K;

    dp[1][1] = 1;
    dp[2][1] = 2;
    dp[3][1] = 3; dp[3][2] = 1;
    for (int i = 4; i <= N; i++)
    {
        dp[i][1] = i;

        for (int j = 2; j <= N/2; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % DIV; // (선택하지 않은 경우) + (선택한 경우)
        }
    }

    if (N / 2 < K)
    {
        cout << 0;
        return 0;
    }
    else if (K == 1)
    {
        cout << N;
        return 0;
    }

    cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % DIV;
}