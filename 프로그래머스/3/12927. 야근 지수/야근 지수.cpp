#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer=0;
    priority_queue<int> pq;
    for(int i=0;i<works.size();i++)
    {
        pq.push(works[i]);
    }
    
    while(n!=0 && !pq.empty())
    {
        int num = pq.top();
        pq.pop();
        num--;
        
        if(num!=0)
        {
            pq.push(num);
        }
        n--;
    }
    
    while(!pq.empty())
    {
        int num = pq.top();
        pq.pop();
        answer+=num*num;
    }
    return answer;
}