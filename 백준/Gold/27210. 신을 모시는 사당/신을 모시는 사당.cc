#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int arr[100001] = { 0, };
    int dp[100001][3] = {0,};
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i] == 1)
        {
            dp[i][1] = max(dp[i - 1][1] + 1, 1);
            dp[i][2] = dp[i - 1][2] - 1;
        }
        else
        {
            dp[i][2] = max(dp[i - 1][2] + 1, 1);
            dp[i][1] = dp[i - 1][1] - 1;
        }

        answer = max(max(dp[i][1], dp[i][2]),answer);
    }
    cout << answer;
}