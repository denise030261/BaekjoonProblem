#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string addBigNumbers(const string& a, const string& b) 
{
    string result = "";
    int carry = 0, sum = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) 
    {
        int num1 = (i >= 0) ? a[i--] - '0' : 0;
        int num2 = (j >= 0) ? b[j--] - '0' : 0;

        sum = num1 + num2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    reverse(result.begin(), result.end());
    return result;
}

string multiplyByTwo(const string& a) 
{
    string result = "";
    int carry = 0, product = 0;

    for (int i = a.size() - 1; i >= 0; --i) 
    {
        product = (a[i] - '0') * 2 + carry;
        carry = product / 10;
        result += (product % 10) + '0';
    }

    if (carry) 
        result += carry + '0';
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
    vector<string> dp(251);
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";

	for (int i = 3; i <= 250; i++)
	{
        dp[i] = addBigNumbers(dp[i - 1], multiplyByTwo(dp[i - 2]));
	}

	while (cin >> n)
	{
		cout << dp[n] << '\n';
	}
}