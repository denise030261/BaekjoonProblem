#include <iostream>

using namespace std;

int parent[500000] = { 0, };

int FindParent(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = FindParent(parent[x]);
}

void UnionParent(int a, int b)
{
    a = FindParent(a);
    b = FindParent(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    bool bMade = false;
    int answer = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        if (FindParent(a) == FindParent(b) && !bMade)
        {
            bMade = true;
            answer = i + 1;
        }
        else if(FindParent(a) != FindParent(b))
        {
            UnionParent(a, b);
        }
    }

    cout << answer;
}
