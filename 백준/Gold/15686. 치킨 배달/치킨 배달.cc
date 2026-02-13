#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int answer = INT_MAX;
int N, M;
int arr[50][50] = { 0, };
int chicken_dist[13][100] = { 0, }; // 치킨집에서 집으로부터의 거리
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(vector<int> v,int index)
{
    if (v.size() == M)
    {
        int sum = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int num = INT_MAX;
            for (int j = 0; j < v.size(); j++)
            {
                num = min(num, chicken_dist[v[j]][i]);
            }
            sum += num;
        }
        answer = min(answer, sum);
        return;
    }

    for (int i = index; i < chicken.size(); i++)
    {
        v.push_back(i);
        dfs(v, i + 1);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            
            if (arr[i][j] == 1)
            {
                house.push_back({ i,j });
            }
            else if (arr[i][j] == 2)
            {
                chicken.push_back({ i,j });
            }
        }
    }

    for (int i = 0; i < chicken.size(); i++)
    {
        for (int j = 0; j < house.size(); j++)
        {
            chicken_dist[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < chicken.size(); i++)
    {
        int chicken_x = chicken[i].first;
        int chicken_y = chicken[i].second;

        for (int j = 0; j < house.size(); j++)
        {
            int house_x = house[j].first;
            int house_y = house[j].second;

            int dist = abs(chicken_x - house_x) + abs(chicken_y - house_y);
            chicken_dist[i][j] = dist;
        }
    }

    vector<int> v;
    dfs(v, 0);

    cout << answer;
}