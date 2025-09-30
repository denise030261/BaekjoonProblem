#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}

	return a.length() < b.length();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	vector<string> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		string strNum = "";
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{
				strNum += str[j];
			}
			else if(strNum.length()!=0)
			{
				if (strNum.length() != 1)
				{
					while (strNum[0]=='0' && strNum.length() != 1)
					{
						strNum.erase(strNum.begin());
					}
				}
				v.push_back(strNum);
				strNum = "";
			}
		}
		if (strNum.length() != 0)
		{
			if (strNum.length() != 1)
			{
				while (strNum[0] == '0' && strNum.length() != 1)
				{
					strNum.erase(strNum.begin());
				}
			}
			v.push_back(strNum);
			strNum = "";
		}
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}