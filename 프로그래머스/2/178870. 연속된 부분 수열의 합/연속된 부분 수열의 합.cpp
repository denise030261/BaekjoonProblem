#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(987654321);
    int start=0;
    int end=0;
    int count=sequence[0];
    while(start<sequence.size() && end<sequence.size())
    {
        if(count<k)
        {
            if(end+1<sequence.size())
            {   
                end++;
                count+=sequence[end];
            }
            else
            {
                break;
            }
        }
        else if(count>k)
        {
            count-=sequence[start];
            start++;
        }
        else if((answer[1]-answer[0])>(end-start))
        {
            answer[0]=start;
            answer[1]=end;
            end++;
            count+=sequence[end];
        }
        else
        {
            end++;
            count+=sequence[end];
        }
    }
    return answer;
}