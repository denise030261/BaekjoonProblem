#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	bool bits[1000001] = { 0, };
	cin >> N >> K;

	int cnt = 0;
	int curBottle = 0;
	while (1)
	{
		if (N == 1)
		{
			bits[cnt] = 1;
			curBottle++;
			break;
		}
		bits[cnt] = N % 2;
		if (bits[cnt])
			curBottle++;
		N /= 2;
		cnt++;
	}

	int needBottle = 0;
	int maxCnt = cnt;
	while (curBottle > K)
	{
		needBottle++;
		cnt = 0;
		if (bits[cnt])
		{
			while (bits[cnt] && maxCnt >= cnt)
			{
				bits[cnt] = !bits[cnt];
				curBottle--;
				cnt++;
			}
			bits[cnt] = !bits[cnt];
			if(cnt<=maxCnt)
				curBottle++;
		}
		else
		{
			bits[cnt] = !bits[cnt];
			curBottle++;
		}
	}

	cout << needBottle;
}