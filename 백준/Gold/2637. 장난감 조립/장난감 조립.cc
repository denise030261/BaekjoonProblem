#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> parts[101];
vector<int> basicParts;
bool basicPartsIndex[101];
int needParts[101];
bool visited[101] = { 0, };
int dp[101][101] = { 0, };

void dfs(int part)
{ 
    if (visited[part]) 
	{ 
        return;
    }
    visited[part] = true; 

    for (auto& required : parts[part]) 
	{
        int usePart = required.first;
        int useNum = required.second; 

        if (basicPartsIndex[usePart]) 
		{
            dp[part][usePart] += useNum;
        }
        else {
            dfs(usePart);

            for (int k = 1; k <= N; k++) 
			{ 
                if (dp[usePart][k] > 0) 
				{ 
                    dp[part][k] += dp[usePart][k] * useNum;
                }
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int X, Y, K;
		cin >> X >> Y >> K;
		parts[X].push_back({ Y,K });
	}

	for (int i = 1; i < N; i++)
	{
		if (parts[i].size() == 0)
		{
			basicParts.push_back(i);
			basicPartsIndex[i] = true;
		}
	}
	sort(basicParts.begin(), basicParts.end());

	dfs(N);
	for (int i = 1; i <=N; i++)
	{
		if (dp[N][i] != 0)
		{
			cout << i << ' ' << dp[N][i] << '\n';
		}
	}

}