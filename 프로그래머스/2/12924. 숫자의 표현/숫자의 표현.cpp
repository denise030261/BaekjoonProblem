#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int start=0;
    int end=0;
    int sum=0;
    while(start<=n && end<=n && start<=end)
    {
        if(sum<n)
        {
            end++;
            sum+=end;
        }
        else if(sum>n)
        {
            start++;
            sum-=start;
        }
        else
        {
            answer++;
            end++;
            sum+=end;
        }
    }
    return answer;
}