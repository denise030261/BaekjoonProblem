#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define DIV 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int dp[100001]={0,};
    sort(money.begin(), money.end());
    
    dp[0]=1;
    for(int i=0;i<money.size();i++)
    {
        int coin = money[i];
        for(int j=coin;j<=n;j++)
        {
            dp[j] = dp[j] + dp[j-coin];
        }
    }
    answer=dp[n];
    return answer;
}