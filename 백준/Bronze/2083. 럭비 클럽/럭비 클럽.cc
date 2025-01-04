#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	int age, weight;
	while (1)
	{
		cin >> str >> age >> weight;
		if (str == "#" && age == 0 && weight == 0)
			break;

		if (age > 17 || weight >= 80)
			cout << str << ' ' << "Senior";
		else
			cout << str << ' ' << "Junior";

		cout << '\n';
	}
}