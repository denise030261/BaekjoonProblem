#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    string str = to_string(storey);
    
    int add=0;
    for(int i=0;i<str.length();i++)
    {
        int num = str[str.length()-1-i]-'0';
        if(add!=0)
        {
            num+=add;
            add=num/10;
            num%=10;
        }
        
        if(num>5 || num==5 && str[str.length()-2-i]>='5')
        {
            add++;
            answer+=10-num;
        }
        else
        {
            answer+=num;
        }
    }
    if(add!=0)
    {
        answer++;
    }
    return answer;
}