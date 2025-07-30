#include <iostream>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    for(long long i=1;i<=w-1;i++)
    {
        long long num = (long long)h-(long long)(((long long)h*i)/(long long)w);
        if(((long long)h*i)%(long long)w==0)
        {
            answer+=num;
        }
        else
        {
            answer+=num-(long long)1;
        }
        //answer+=h-((h*i)/w);
        //cout << h-((h*i)/w)<<'\n';
    }
    answer=answer+answer;
    return answer;
}