#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, A, B, C;
	vector<int> D;
	int answer = 0;
	cin >> N;
	cin >> A >> B;
	cin >> C;

	int toppings = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> toppings;
		D.push_back(toppings);
	}
	
	sort(D.begin(), D.end(), compare);

	int sumToppings = 0;
	int sumToppingsCost = 0;
	answer = C / A;
	for (int i = 0; i < D.size(); i++)
	{
		sumToppingsCost += B;
		sumToppings += D[i];
		int calorie = (C + sumToppings) / (A + sumToppingsCost);
		if (answer <= calorie)
		{
			answer = calorie;
		}
		else
		{
			break;
		}
	}
	cout << answer;
}