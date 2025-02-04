#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, S;
	vector<int> v;
	cin >> N >> S;

	int standard = 0;
	int sum = 0;
	int length = 0;
	int answer = INT_MAX;
	int num = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);

		sum += num;
		length++;
		if (sum >= S)
		{
			answer = min(answer, length);
			for (int j = standard; j < i; j++)
			{
				standard++;
				sum -= v[j];
				length--;

				if (sum >= S)
				{
					answer = min(answer, length);
				}
				else
				{
					break;
				}
			}
		}
	}

	if (answer == INT_MAX)
		cout << 0;
	else
		cout << answer;
}