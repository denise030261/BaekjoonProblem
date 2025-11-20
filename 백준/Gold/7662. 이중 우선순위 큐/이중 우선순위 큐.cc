#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T != 0)
	{
		multiset<int> arr;
		int order;
		cin >> order;
		while (order != 0)
		{
			char c;
			int element;
			cin >> c >> element;
			if (c == 'I')
			{
				arr.insert(element);
				order--;
			}
			else
			{
				if (arr.empty())
				{
					order--;
					continue;
				}
				if (element == 1)
				{
					auto E = arr.end();
					E--;
					arr.erase(E);
				}
				else if(element == -1)
					arr.erase(arr.begin());
				order--;
			}

		}

		if (arr.empty())
			cout << "EMPTY" << '\n';
		else
		{
			auto E = arr.end();
			E--;
			cout << *E << ' ' << *(arr.begin()) << '\n';
		}
		T--;
	}
}