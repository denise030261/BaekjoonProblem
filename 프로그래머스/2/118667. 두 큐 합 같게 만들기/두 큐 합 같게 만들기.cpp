#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long int answer = 0;
    queue<long long int> q1;
    queue<long long int> q2;
    long long int q1Sum=0;
    long long int q2Sum=0;
    long long int maxNum=0;
    
    for(int i=0;i<queue1.size();i++)
    {
        long long int num =queue1[i];
        q1Sum+=num;
        q1.push(num);
        maxNum=max(maxNum,num);
    }
    
    for(int i=0;i<queue2.size();i++)
    {
        long long int num =queue2[i];
        q2Sum+=num;
        q2.push(num);
        maxNum=max(maxNum,num);
    }
    
    while(q1Sum!=q2Sum)
    {
        if(q1.size()*6<answer || maxNum>(q1Sum+q2Sum-maxNum))
        {
            answer=-1;
            break;
        }
        
        long long int num; // 옮길 숫자
        if(q1Sum<q2Sum)
        {
            num = q2.front();
            q2Sum-=num;
            q2.pop();
            q1Sum+=num;
            q1.push(num);
        }
        else if(q1Sum>q2Sum)
        {
            num = q1.front();
            q1Sum-=num;
            q1.pop();
            q2Sum+=num;
            q2.push(num);
        }
        else
        {
            break;
        }
        
        answer++;
    }
    
    return answer;
}