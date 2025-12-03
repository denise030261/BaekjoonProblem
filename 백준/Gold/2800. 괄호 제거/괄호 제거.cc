#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

map<string,int> m;

void dfs(int index,string str, vector<pair<int, int>> v)
{
    for (int i = index; i < v.size(); i++)
    {
        string origin = str;
        vector<int> fir;
        vector<int> sec;

        int front = v[i].first;
        int second = v[i].second;

        origin.erase(front, 1);
        second--;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j].first > front)
            {
                v[j].first--; fir.push_back(j);
            }
            if (v[j].second > front)
            {
                v[j].second--; sec.push_back(j);
            }
        }

        origin.erase(second, 1);
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j].first > second)
            {
                v[j].first--; fir.push_back(j);
            }
            if (v[j].second > second)
            {
                v[j].second--; sec.push_back(j);
            }
        }

        m[origin]++;
        //cout <<index<< " : " <<  origin << '\n';
        dfs(i + 1, origin, v);
        for (int j = 0; j < fir.size(); j++)
        {
            v[fir[j]].first++;
        }
        for (int j = 0; j < sec.size(); j++)
        {
            v[sec[j]].second++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    vector<pair<int, int>> v;
    cin >> str;
    
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            s.push(i);
        }
        else if (str[i] == ')')
        {
            v.push_back({ s.top(),i });
            s.pop();
        }
    }

    dfs(0, str,v);

    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second != 0)
        {
            cout << iter->first << '\n';
        }
    }
}