#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, K;
vector<char> v;
vector<char> cur;
set<char> s;
bool arr[50][26] = { 0, };
int arrNeed[50] = { 0, };
int answer = 0;

void dfs(int length, int index)
{
    if (length == K)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            int need = 0;
            for (int j = 0; j < cur.size(); j++)
            {
                if (arr[i][cur[j] - 'a'])
                {
                    need++;
                }
            }

            if (need == arrNeed[i])
            {
                sum++;
            }
        }

        answer = max(answer, sum);
        return;
    }

    for (int i = index; i < v.size(); i++)
    {
        cur.push_back(v[i]);
        dfs(length + 1, i + 1);
        cur.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] != 'a' && str[j] != 'n' && str[j] != 't' && str[j] != 'i' && str[j] != 'c'
                 && !arr[i][str[j] - 'a'])
            {
                arr[i][str[j] - 'a'] = true;
                arrNeed[i]++;
                s.insert(str[j]);
            }
        }
    }

    K -= 5;
    if (K < 0)
    {
        cout << 0;
        return 0;
    }

    for (auto element : s)
    {
        v.push_back(element);
    }

    if (K < v.size())
    {
        dfs(0, 0);
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            int need = 0;
            for (int j = 0; j < v.size(); j++)
            {
                if (arr[i][v[j] - 'a'])
                {
                    need++;
                }
            }

            if (need == arrNeed[i])
            {
                sum++;
            }
        }
        answer = max(answer, sum);
    }
    
    cout << answer;
}