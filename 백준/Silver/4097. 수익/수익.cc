#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> answer; //가장 많은 수익

	while (1)
	{
		int N;
		int total = 0;
		int result = -100000;
		cin >> N;

		if (N == 0)
			break;

		else
		{
			for (int i = 0; i < N; i++)
			{
				int num;
				cin >> num;

				total += num;

				if (total < num)
					total = num;
				if (result < total)
					result = total;
			}
		}

		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';
}