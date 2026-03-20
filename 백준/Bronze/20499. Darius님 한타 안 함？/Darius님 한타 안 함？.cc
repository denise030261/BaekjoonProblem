#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;

	int index = 0;
	int num[3] = { 0, };
	string temp = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '/')
		{
			num[index] = stoi(temp);
			index++;
			temp = "";
		}
		else
		{
			temp += str[i];
		}
	}
	num[index] = stoi(temp);

	if (num[0] + num[2] < num[1] || num[1] == 0)
	{
		cout << "hasu";
	}
	else
	{
		cout << "gosu";
	}
}