#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void Hanoi(int num,int start, int end)
{
    if(num==1)
    {
        answer.push_back({start,end});
        return;
    }
    
    Hanoi(num-1, start, 6-start-end);
    Hanoi(1,start,end);
    Hanoi(num-1, 6-start-end, end);
}

vector<vector<int>> solution(int n) {
    Hanoi(n,1,3);
    return answer;
}