#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    queue<string> q;
    if(cacheSize==0)
    {
        return 5*cities.size();
    }
    
    for(int i=0;i<cities.size();i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    
    for(int i=0;i<cities.size();i++)
    {
        queue<string> origin;
        bool bexist=false;
        while(!q.empty())
        {
            string str=q.front();
            if(str==cities[i])
            {
                bexist=true;
                answer++;
                q.pop();
            }
            else
            {
                q.pop();
                origin.push(str); 
            }
        }
        
        if(!bexist)
        {
            if(origin.size()==cacheSize)
            {
                origin.pop();
            }
            
            answer+=5;
        }
        
        while(!origin.empty())
        {
            q.push(origin.front());
            origin.pop();
        }
        q.push(cities[i]);
    }
    return answer;
}