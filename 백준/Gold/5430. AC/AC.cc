#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	while (T != 0)
	{
		string p;
		string str;
		int size;
		int	num;
		int check = 0;
		int rev = 0;
		deque<int> dq;
		cin >> p >> size >> str;

		for (int i = 0; i < str.length(); i++)
		{
			if (isdigit(str[i]))
			{
				if (isdigit(str[i + 1]) && isdigit(str[i + 2]))
				{
					dq.push_back((str[i] - '0') * 100 + (str[i + 1] - '0') * 10 
						+ (str[i + 2] - '0'));
					i+=2;
				}

				else if(isdigit(str[i + 1]))
				{
					dq.push_back((str[i] - '0') * 10 + (str[i + 1] - '0'));
					i++;
				}

				else
					dq.push_back(str[i]-'0');
			}
		}
		
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
				rev++;
			else
			{
				if (dq.size() == 0)
				{
					cout << "error" << '\n';
					check++;
					break;
				}
				
				if (rev % 2 == 0)
					dq.pop_front();

				else
					dq.pop_back();
			}
		}

		if (dq.size() != 0)
		{
			cout << '[';
			if (rev % 2 == 1)
				reverse(dq.begin(), dq.end());
			for (int i = 0; i < dq.size(); i++)
			{
					cout << dq[i];
					if (i != dq.size() - 1)
						cout << ',';
			}
			cout << ']' <<'\n';
		}

		else if (dq.size() == 0 && !check)
		{
			cout << "[]" << '\n';
		}

		T--;
	}
}