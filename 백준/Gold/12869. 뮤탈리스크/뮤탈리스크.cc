#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;
bool visited[61][61][61] = { 0, };

int main() //크기가 작고 색이 다른 공
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    vector<int> v;
    int attack[3] = { 9,3,1 };
    int way[6][3] = { {0,1,2},{0,2,1},{1,0,2},{1,2,0} ,{2,1,0},{2,0,1} };

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(-num);
    }

    while (v.size() != 3)
    {
        v.push_back(0);
    }
    queue <pair<vector<int>, int>> q;
    q.push({ v,0 });
    int answer = INT_MAX;
    while (!q.empty())
    {
        vector<int> nums = q.front().first;
        int cost = q.front().second;
        q.pop();

        if ((cost > answer))
        {
            continue;
        }

        if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0)
        {
            cout << cost;
            return 0;
        }
        
        for (int j = 0; j < 6; j++)
        {
            vector<int> temp;
            for (int k = 0; k < nums.size(); k++)
            {
                int num = -(-nums[k] - attack[way[j][k]]);
                num = min(num, 0);
                temp.push_back(num);
            }
            
            if (!visited[abs(temp[0])][abs(temp[1])][abs(temp[2])])
            {
                q.push({ temp,cost + 1 });
                visited[abs(temp[0])][abs(temp[1])][abs(temp[2])] = true;
            }
        }
    }

    cout << answer;
}