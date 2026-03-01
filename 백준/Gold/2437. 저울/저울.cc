#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
set<int> s;
bool visited[1000] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int num = v[i];
        if (answer + 1 < num)
        {
            cout << answer + 1;
            return 0;
        }
        else
        {
            answer += num;
        }
    }

    cout << answer + 1;
}