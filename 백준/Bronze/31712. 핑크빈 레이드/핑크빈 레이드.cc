#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int pinkbin = 0;
	int second[3] = { 0, };
	int damage[3] = { 0, };
	
	for (int i = 0; i < 3; i++)
		cin >> second[i] >> damage[i];

	cin >> pinkbin;

	int flow = -1;
	while (pinkbin > 0)
	{
		flow++;
		for (int i = 0; i < 3; i++)
		{
			if (flow % second[i] == 0)
				pinkbin -= damage[i];
		}
	}

	cout << flow;
}