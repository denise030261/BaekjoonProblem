#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int result = 64;
string board[50];
string wb[8] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};

string bw[8] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};

void wbcpr(int x, int y)
{
	int count = 0;
	for(int i=0;i<8;i++)
		for (int j = 0;j < 8;j++)
		{
			if (wb[i][j] != board[y + i][x + j])
				count++;
		}
	if (count < result)
		result = count;
}

void bwcpr(int x, int y)
{
	int count = 0;
	for (int i = 0;i < 8;i++)
		for (int j = 0;j < 8;j++)
		{
			if (bw[i][j] != board[y + i][x + j])
				count++;
		}
	if (count < result)
		result = count;
}

int main()
{
	int m, n = 0;
	cin >> m >> n;
	for (int i = 0;i < m;i++)
		cin >> board[i];
	for(int y=0;y<m-7;y++)
		for (int x = 0;x < n - 7;x++)
		{
			wbcpr(x, y);
			bwcpr(x, y);
		}
	cout << result;
	return 0;
}