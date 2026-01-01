#include <iostream>
#include <vector>

using namespace std;

long long int CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    long long int num = 0;
    num = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    return num;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    long long circle1 = CCW(x3, y3, x1, y1, x2, y2);
    long long circle2 = CCW(x4, y4, x1, y1, x2, y2);
    long long circle3 = CCW(x1, y1, x3, y3, x4, y4);
    long long circle4 = CCW(x2, y2, x3, y3, x4, y4);

    //cout << circle1 << ' ' << circle2 << ' ' << circle3 << ' ' << circle4 << '\n';

    if ((circle1 > 0 && circle2 < 0) || (circle1 < 0 && circle2 > 0) || (circle1 == 0 && circle2 > 0) || (circle1 == 0 && circle2 < 0)
        || (circle1 > 0 && circle2 == 0) || (circle1 < 0 && circle2 == 0))
    {
        //cout << "pass\n";
        if ((circle3 > 0 && circle4 < 0) || (circle3 < 0 && circle4 > 0) || (circle3 == 0 && circle4 > 0) || (circle3 == 0 && circle4 < 0)
            || (circle3 > 0 && circle4 == 0) || (circle3 < 0 && circle4 == 0))
        {
            cout << 1;
            return 0;
        }
    }

    if (circle1 == 0 && circle2 == 0 && circle3 == 0 && circle4 == 0)
    {
        int X1 = min(x1, x2);
        int Y1 = min(y1, y2);
        int X2 = max(x1, x2);
        int Y2 = max(y1, y2);
        int X3 = min(x3, x4);
        int Y3 = min(y3, y4);
        int X4 = max(x3, x4);
        int Y4 = max(y3, y4);
        //cout << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2 << ' ' << X3 << ' ' << Y3 << ' ' << X4 << ' ' << Y4 << '\n';

        if ((((X1 <= X3 && X3 <= X2) || (X1 <= X4 && X4 <= X2)) && ((Y1 <= Y3 && Y3 <= Y2) || (Y1 <= Y4 && Y4 <= Y2)))
            || (((X3 <= X1 && X1 <= X4) || (X3 <= X2 && X2 <= X4)) && ((Y3 <= Y1 && Y1 <= Y4) || (Y3 <= Y2 && Y2 <= Y4))))
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}