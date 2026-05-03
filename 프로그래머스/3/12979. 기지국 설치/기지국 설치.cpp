#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<pair<int,int>> v; // stations의 사이에 있는 숫자들 (처음~끝)
    
    if(1<stations[0]-w)
    {
        v.push_back({1,stations[0]-w-1});
    }
    for(int i=1;i<stations.size();i++)
    {
        if((stations[i]-w)-(stations[i-1]+w)>1)
        {
            v.push_back({stations[i-1]+w+1,stations[i]-w-1});
        }
    }
    if(n>stations[stations.size()-1]+w)
    {
        v.push_back({stations[stations.size()-1]+w+1,n});
    }
    
    for(int i=0;i<v.size();i++)
    {
        int start = v[i].first;
        int end = v[i].second;
        int sum = end-start+1;
        
        answer+=sum/(1+w*2);
        if(sum%(1+w*2)!=0)
        {
            answer++;
        }
    }

    return answer;
}