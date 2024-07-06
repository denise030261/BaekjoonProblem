#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> sticks; // 막대기들
	int sum = 0; // 막대기들의 길이 합
	int stick1 = 0; // 쪼개진 막대기1
	int stick2 = 0; // 쪼개진 막대기2
	int X;

	sticks.push_back(64);
	cin >> X;

	while (sum!=X)
	{
		if (X == 64)
			break;

		stick1 = sticks[sticks.size() - 1] / 2;
		stick2 = sticks[sticks.size() - 1] / 2; // 가장 짧은 것을 절반 자르기
		sticks.pop_back();
		sticks.push_back(stick2);
		sum = 0;
		for (int i = 0; i < sticks.size(); i++)
			sum += sticks[i]; // 버리고 남은 것들끼리 더하기
	
		if (sum<X)
		{
			sum += stick1;
			sticks.push_back(stick1);
		} //작다면 다시 더하기
	}

	int result = sticks.size();
	cout << result;
}