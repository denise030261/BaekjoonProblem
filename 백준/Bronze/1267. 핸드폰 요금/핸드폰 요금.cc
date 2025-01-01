#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int Y = 0; // 10 per 30 seconds
    int M = 0; // 15 per 60 seconds
    int N;
    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        Y += ((num / 30) + 1)*10;
        M += ((num / 60) + 1)*15;
    }

    if (Y < M)
    {
        cout << "Y " << Y;
    }
    else if (M < Y)
    {
        cout << "M " << M;
    }
    else
    {
        cout << "Y M " << Y;
    }
}