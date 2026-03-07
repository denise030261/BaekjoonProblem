#include <iostream> 
#include <cmath>

using namespace std;

int cur_y, cur_m, cur_d;
int next_y, next_m, next_d;
int answer = 0;
bool done = false;

int calculate(int cur_year, int cur_month, int day)
{
    int sum = 0;

    if (cur_month == 2)
    {
        if (cur_year % 4 == 0)
        {
            if(cur_year%400==0 || cur_year%100!=0)
            {
                sum += abs(29 - day);
            }
            else
            {
                sum += abs(28 - day);
            }
        }
        else
        {
            sum += abs(28-day);
        }
    }
    else if (cur_month == 4 || cur_month == 6 || cur_month == 9 || cur_month == 11)
    {
        sum += abs(30-day);
    }
    else
    {
        sum += abs(31-day);
    }
    //cout << sum << ' ';

    return sum;
}

int changeDay(int cur_y, int cur_m)
{
    int day = 0;
    if (cur_m == 2)
    {
        if (cur_y % 4 == 0)
        {
            if (cur_y % 400 == 0 || cur_y % 100 != 0)
            {
                day += 29;
            }
            else
            {
                day += 28;
            }
        }
        else
        {
            day += 28;
        }
    }
    else if (cur_m == 4 || cur_m == 6 || cur_m == 9 || cur_m == 11)
    {
        day += 30;
    }
    else
    {
        day += 31;
    }
    return day;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> cur_y >> cur_m >> cur_d;
    cin >> next_y >> next_m >> next_d;

    if(abs(cur_y-next_y)>1000 || (abs(cur_y - next_y) == 1000 && (cur_m<next_m))
        || (abs(cur_y - next_y) == 1000 && (cur_m == next_m) && (cur_d<=next_d)))
    {
        cout << "gg";
        return 0;
    }

    answer += calculate(cur_y, cur_m, cur_d);
    for (int i = cur_m + 1; i <= 12; i++)
    {
        if (cur_y == next_y
            && next_m==i)
        {
            next_d += changeDay(cur_y, i);
            answer += calculate(cur_y, i, next_d);
            done = true;
            break;
        }
        else
        {
            answer += calculate(cur_y, i, 0);
        }
    }
    
    for (int i = 1; i <= 1000; i++)
    {
        if (done)
        {
            break;
        }

        cur_y++;
        for (int j = 1; j <= 12; j++)
        {
            if (cur_y == next_y
                && next_m == j)
            {
                next_d += changeDay(cur_y, j);
                answer += calculate(cur_y, j, next_d);
                done = true;
                break;
            }
            else
            {
                answer += calculate(cur_y, j, 0);
            }
        }
    }
    
    cout << "D-" << answer;
}