#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string str;
	int answer = 0;
	map < string, bool > dic;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		
		if (str == "ENTER")
		{
			dic.clear();
		} // init
		else
		{
			if (dic[str]==false)
			{
				dic[str] = true;
				answer++;
			} // not exist
		}
	}

	cout << answer;
}