#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i=0;i*k<=d;i++)
    {
        long long num = sqrt((long long)pow(d,2)-(long long)pow(i*k,2));
        answer+=(num/k)+1;
    }
    return answer;
}