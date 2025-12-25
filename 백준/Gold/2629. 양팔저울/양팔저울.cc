#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

int N, M;
bool dp[31][15001];
vector<int> weights;
vector<int> beads;

void dfs(int index, int current_weight)
{
    if (index > N || dp[index][current_weight]) 
        return;

    dp[index][current_weight] = true;
    if (index == N) 
        return;

    dfs(index + 1, current_weight + weights[index]);
    dfs(index + 1, current_weight);
    dfs(index + 1, abs(current_weight - weights[index]));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        weights.push_back(num);
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        beads.push_back(num);
    }

    dfs(0, 0);

    for (int i = 0; i < M; i++)
    {
        if (beads[i] > 15000)
        {
            cout << "N ";
        }
        else if (dp[N][beads[i]])
        {
            cout << "Y ";
        }
        else
        {
            cout << "N ";
        }
    }
}