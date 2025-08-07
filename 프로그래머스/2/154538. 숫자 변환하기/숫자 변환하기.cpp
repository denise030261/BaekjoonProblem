#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    long int answer = INT_MAX;
    priority_queue<pair<long int,long int>> pq;
    bool visited[1000001]={0,};
    pq.push({-0,y});
    while(!pq.empty())
    {
        long int sum=-pq.top().first;
        long int num=pq.top().second;
        visited[num]=true;
        pq.pop();
        
        if(num==x)
        {
            answer=min(sum,answer);
        }
        
        if(num-n>=x && !visited[num-n])
            pq.push({-(sum+1), num-n});
        if(num/2>=x && num%2==0 && !visited[num/2])
            pq.push({-(sum+1), num/2});
        if(num/3>=x && num%3==0 && !visited[num/3])
            pq.push({-(sum+1), num/3});
    }
    
    if(answer==INT_MAX)
    {
        answer=-1;
    }
    return answer;
}