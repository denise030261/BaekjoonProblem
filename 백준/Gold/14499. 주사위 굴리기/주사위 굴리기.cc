#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	int x, y; // 현재 위치

	int map[20][20] = { 0, };
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	int diceLoc[6] = { 0, }; 
	
	vector<int> orders;
	
	cin >> N >> M;
	cin >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		orders.push_back(num);
	}

	for (int i = 0; i < orders.size(); i++)
	{
		int order = orders[i];
		int next_x = x + dx[order-1];
		int next_y = y + dy[order-1];
		//cout << "명령어의 위치 : " << next_x << ' ' << next_y << ' ';
		if (!(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M))
		{
			continue;
		} // 지도에서 벗어나면 다음 명령어로
		
		x = next_x;
		y = next_y;

		int dicePreLoc[6] = { 0, };
		//cout << "주사위 명령어의 이전 위치 : ";
		for (int j = 0; j < 6; j++)
		{
			//cout << diceLoc[j] << ' ';
			dicePreLoc[j] = diceLoc[j];
		}

		if (order == 1)
		{
			diceLoc[0] = dicePreLoc[3];
			diceLoc[2] = dicePreLoc[0];
			diceLoc[3] = dicePreLoc[5];
			diceLoc[5] = dicePreLoc[2];
		} // 동
		else if (order == 2)
		{
			diceLoc[0] = dicePreLoc[2];
			diceLoc[2] = dicePreLoc[5];
			diceLoc[3] = dicePreLoc[0];
			diceLoc[5] = dicePreLoc[3];
		} // 서
		else if (order == 4)
		{
			diceLoc[0] = dicePreLoc[1];
			diceLoc[1] = dicePreLoc[5];
			diceLoc[4] = dicePreLoc[0];
			diceLoc[5] = dicePreLoc[4];
		} // 북
		else
		{
			diceLoc[0] = dicePreLoc[4];
			diceLoc[1] = dicePreLoc[0];
			diceLoc[4] = dicePreLoc[5];
			diceLoc[5] = dicePreLoc[1];
		} // 남

		/*cout << "주사위 명령어의 이후 위치 : ";
		for (int j = 0; j < 6; j++)
		{
			cout << diceLoc[j] << ' ';
		}
		cout << map[x][y] << '\n';*/

		if(map[x][y]!=0)
		{
			diceLoc[5] = map[x][y];
			map[x][y] = 0;
		}
		else
		{
			map[x][y] = diceLoc[5];
		}
		cout << diceLoc[0] << '\n';
	}
}