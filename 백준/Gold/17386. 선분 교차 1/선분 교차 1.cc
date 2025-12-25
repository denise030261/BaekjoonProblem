#include <iostream>
#include <vector>

using namespace std;

long long int CCW(long long int x1, long long int y1, long long int x2, long long int y2,
    long long int x3, long long int y3)
{
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    long long int  circle1 = CCW(x1, y1, x3, y3, x2, y2);
    long long int  circle2 = CCW(x1, y1, x4, y4, x2, y2);
    long long int  circle3 = CCW(x3, y3, x1, y1, x4, y4);
    long long int  circle4 = CCW(x3, y3, x2, y2, x4, y4);


    if ((circle1 > 0 && circle2 < 0) || (circle1 < 0 && circle2 > 0))
    {
        if ((circle3 > 0 && circle4 < 0) || (circle3 < 0 && circle4 > 0))
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}