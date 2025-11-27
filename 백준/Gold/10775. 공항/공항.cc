#include <iostream>

using namespace std;

int gate[100001] = { 0, };

int Find(int x)
{
    if (x == gate[x])
    {
        return x;
    }

    return gate[x] = Find(gate[x]);
}


void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);

    if (x > y)
    {
        gate[x] = y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int G, P;
    int answer = 0;
    cin >> G >> P;

    for (int i = 1; i <= G; i++)
    {
        gate[i] = i;
    }

    for (int i = 0; i < P; i++)
    {
        int plane = 0;
        cin >> plane;
        plane = Find(plane);

        if (plane == 0)
        {
            break;
        }
        
        Union(plane, plane - 1);

        answer++;
    }
    cout << answer;
}