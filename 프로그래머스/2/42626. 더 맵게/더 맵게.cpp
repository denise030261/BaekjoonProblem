#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long int, vector<long long int>,greater<long long int>> pq;
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]);
    }
    
    int first=0;
    int second=0;
    while(K>pq.top() && pq.size()>1)
    {
        answer++;
        first=pq.top();
        pq.pop();
        second=pq.top();
        pq.pop();
        
        pq.push(first+second*2);
    }
    
    if(pq.size()==1 && pq.top()<K)
        return -1;
    return answer;
}