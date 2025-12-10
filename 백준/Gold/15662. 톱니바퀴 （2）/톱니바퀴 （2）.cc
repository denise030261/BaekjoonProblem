#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

deque<int> d[1000];
void turn(int index,int dir)
{
    if (dir == 1)
    {
        int num = d[index].back();
        d[index].pop_back();
        d[index].push_front(num);
    } // 시계 방향
    else
    {
        int num = d[index].front();
        d[index].pop_front();
        d[index].push_back(num);
    } // 반시계 방향
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            d[i].push_back(str[j] - '0');
        }
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        vector<pair<int, int>> v; // index,dir
        int index, dir;
        cin >> index >> dir;

        index--;
        v.push_back({ index,dir });
        int origin = dir;
        for (int j = index+1; j < T; j++)
        {
            deque<int> preD = d[j - 1];
            deque<int> curD = d[j];
            preD.pop_front(); preD.pop_front();
            int three = preD.front();

            curD.pop_back(); 
            int nine = curD.back();

            if (three != nine)
            {
                dir *= -1;
                v.push_back({ j,dir });
            }
            else
            {
                break;
            }
        }

        dir = origin;
        for (int j = index - 1; j >= 0; j--)
        {
            deque<int> preD = d[j + 1];
            deque<int> curD = d[j];
            preD.pop_back(); 
            int nine = preD.back();

            curD.pop_front(); curD.pop_front();
            int three = curD.front();
            
            if (three != nine)
            {
                dir *= -1;
                v.push_back({ j,dir });
            }
            else
            {
                break;
            }
        }

        for (int j = 0; j < v.size(); j++)
        {
            int turn_index = v[j].first;
            int turn_dir = v[j].second;
            turn(turn_index, turn_dir);
        }
    }

    int answer = 0;
    for (int i = 0; i < T; i++)
    {
        if (d[i].front() == 1)
        {
            answer++;
        }
    }
    cout << answer;
}