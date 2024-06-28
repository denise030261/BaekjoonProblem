#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int arr[1001][1001] = {0,};
	string str1;
	string str2;

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++)
	{
		for (int j = 1; j <= str2.length(); j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else

			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	cout << arr[str1.length()][str2.length()];
}