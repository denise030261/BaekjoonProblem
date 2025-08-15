#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int index=0;
    for(int i=0;i<speeds.size();i++)
    {
        int day=0;
        if((100-progresses[i])%speeds[i]==0)
        {
            day = (100-progresses[i])/speeds[i];
        }
        else
        {
            day = ((100-progresses[i])/speeds[i])+1;
        }
        days.push_back(day);
    }
    
    int boundary=days[0];
    int sum=1;
    for(int i=1;i<days.size();i++)
    {
        if(boundary>=days[i])
        {
            sum++;
        }
        else
        {
            boundary=days[i];
            answer.push_back(sum);
            sum=1;
        }
    }
    cout << sum<<'\n';
    answer.push_back(sum);
    
    return answer;
}