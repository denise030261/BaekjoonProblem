#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long dp[5001]={0,};
    dp[2]=3;
    dp[4]=11;
    for(int i=6;i<=n;i+=2)
    {
        if(i%2==0)
        {
            //cout << dp[i-2] << ' '<<dp[i-4]<<'\n';
            dp[i]+=(dp[i-2]*3)%1000000007;
            for(int j=4;j<=i-2;j+=2)
            {
                dp[i]+=(dp[i-j]*2)%1000000007;
            }
            dp[i]+=2;
        }
    }
    answer=dp[n]%1000000007;
    return answer;
}