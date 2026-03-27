#include <iostream> 
#include <cmath>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

void calculate(int& count_ball, int& count_strike,int num, int candidate)
{
    bool cand[10] = { 0, };
    string cand_str = to_string(candidate);
    int cand_one = cand_str[2]-'0';
    int cand_hundred = cand_str[0] - '0';
    int cand_ten = cand_str[1] - '0';

    string num_str = to_string(num);
    int num_one = num_str[2] - '0';
    int num_hundred = num_str[0] - '0';
    int num_ten = num_str[1] - '0';

    cand[cand_one] = true; cand[cand_hundred] = true; cand[cand_ten] = true;
    if (cand_one == num_one)
    {
        count_strike++;
    }
    else
    {
        if (cand[num_one])
        {
            count_ball++;
        }
    }

    if (cand_ten == num_ten)
    {
        count_strike++;
    }
    else
    {
        if (cand[num_ten])
        {
            count_ball++;
        }
    }

    if (cand_hundred == num_hundred)
    {
        count_strike++;
    }
    else
    {
        if (cand[num_hundred])
        {
            count_ball++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    queue<int> q;
    vector<pair<int, pair<int, int>>> v;
    cin >> N;

    for (int i = 123; i < 1000; i++)
    {
        string str = to_string(i);
        if (str[1]!='0' && str[2]!='0')
        {
            if(str[0]!=str[1] && str[1]!=str[2] && str[0]!=str[2])
            {
                q.push(i);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        int num, strike, ball;
        cin >> num >> strike >> ball;
        v.push_back({ num,{strike, ball} });
    }

    int circle = q.size();
    for (int i = 0; i < circle; i++)
    {
        int candidate = q.front();
        q.pop();

        bool possible = true;
        for (int j = 0; j < v.size(); j++)
        {
            int num = v[j].first;
            int strike = v[j].second.first;
            int ball = v[j].second.second;
            
            int count_strike = 0;
            int count_ball = 0;
            
            calculate(count_ball, count_strike, num, candidate);
            if (count_ball != ball || count_strike != strike)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            q.push(candidate);
        }
    }

    cout << q.size();
}