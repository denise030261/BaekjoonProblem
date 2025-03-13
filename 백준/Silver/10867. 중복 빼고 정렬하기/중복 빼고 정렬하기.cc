#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	set<int> set;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		set.insert(num);
	}

	for (auto it = set.begin(); it != set.end(); it++) 
	{
		cout << *it << " ";
	}

}