#include <iostream> 
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;
vector<int> tree[11];
bool visited[10000] = { 0, };

void dfs(int start, int end, int depth)
{
    if (start > end || start<0 || end>=v.size())
        return;

    int mid = (start + end) / 2;
    tree[depth].push_back(v[mid]);

    dfs(start, mid -1, depth + 1);
    dfs(mid + 1, end, depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int K;
    cin >> K;

    for (int i = 0; i < pow(2, K) - 1; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    dfs(0, v.size()-1, 0);

    for (int i = 0; i < 11; i++)
    {
        if (tree[i].size() == 0)
            break;

        for (int j = 0; j < tree[i].size(); j++)
        {
            cout << tree[i][j] << ' ';
        }
        cout << '\n';
    }
}