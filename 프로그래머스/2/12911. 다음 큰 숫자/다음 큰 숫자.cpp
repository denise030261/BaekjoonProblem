#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int turn(int n)
{
    int one=0;
    while(n!=0)
    {
        int div = n%2;
        if(div==1)
        {
            one+=div;
        }
        n/=2;
    }
    
    return one;
}

int solution(int n) {
    int answer = 0;
    
    int ori=turn(n);
    while(1)
    {
        n++;
        if(ori==turn(n))
        {
            answer=n;
            break;
        }
    }

    return answer;
}