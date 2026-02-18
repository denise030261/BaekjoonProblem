#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, known;
int arr[51] = { 0, };
bool knowns[51] = { 0, };

int Find(int x)
{
    if (x == arr[x])
    {
        return x;
    }

    return Find(arr[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x > y)
    {
        arr[x] = y;
    }
    else
    {
        arr[y] = x;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    cin >> known;
    vector<int> v;

    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < known; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    vector<int> party[50];
    for (int i = 0; i < M; i++)
    {
        int people;
        cin >> people;

        for (int j = 0; j < people; j++)
        {
            int person;
            cin >> person;
            party[i].push_back(person);
        }

        sort(party[i].begin(), party[i].end());

        for (int j = 1; j < people; j++)
        {
            Union(party[i][0], party[i][j]);
        }
    }

    
    for (int i = 0; i < v.size(); i++)
    {
        int cur = Find(v[i]);
        knowns[arr[cur]] = true;
    }

    int answer = 0;
    for (int i = 0; i < M; i++)
    {
        bool possible = false;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (knowns[arr[Find(party[i][j])]])
            {
                possible = true;
                break;
            }
        }

        if (!possible)
        {
            answer++;
        }
    }

    cout << answer;
}