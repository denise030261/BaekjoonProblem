#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int time = 0;
    int times = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> time;
        times += time;
    }

    cout << times / 60 << '\n';
    cout << times % 60;
}