#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int dp[5001] = { 0, };
	cin >> str;

    if (str[0] == '0') 
    {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= str.size(); i++) 
    {
        if (str[i - 1] != '0') 
        {
            dp[i] = dp[i - 1];
        }

        int tmp = stoi(str.substr(i - 2, 2));
        if (tmp >= 10 && tmp <= 26) 
        {
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
        }
    }

    cout << dp[str.size()] % 1000000;
}