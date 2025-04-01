#include <iostream>
#include<algorithm> 
#include<string>
#include <cstring>

using namespace std;

int dp[101][101][101] = {0,};

//string LCS(string str1, string str2)
//{
//	string str = "";
//	for (int i = 1; i <= str1.length(); i++)
//	{
//		for (int j = 1; j <= str2.length(); j++)
//		{
//			if (str1[i - 1] == str2[j - 1])
//			{
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//	}
//
//	int i = str1.size();
//	int j = str2.size();
//	while (i > 0 && j > 0)
//	{
//		if (str1[i - 1] == str2[j - 1])
//		{
//			str += str1[i - 1];
//			i--;
//			j--;
//		}
//		else if (dp[i - 1][j] > dp[i][j - 1])
//		{
//			i--;
//		}
//		else
//		{
//			j--;
//		}
//	}
//
//	reverse(str.begin(), str.end());
//	return str;
//}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str1, str2, str3, str4, str5;

	cin >> str1 >> str2 >> str3;

	string str = "";
	for (int i = 1; i <= str1.length(); i++)
	{
		for (int j = 1; j <= str2.length(); j++)
		{
			for (int k = 1; k <= str3.length(); k++)
			{
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k-1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k-1] + 1;
				}
				else
				{
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}

	cout << dp[str1.length()][str2.length()][str3.length()];
}