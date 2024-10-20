#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer=0;
    long long int sum=0;
    
    int maxSize=*max_element(diffs.begin(),diffs.end());
    int start = diffs[0];
    int end=maxSize;
    
    while(start<=end)
    {
        int level=(start+end)/2;
        sum=0;
        for(int j=0;j<diffs.size();j++)
        {
            sum+=times[j];
            if(diffs[j]>level)
            {
                sum+=(times[j]+times[j-1])*(diffs[j]-level);
            }

            if(sum>limit)
            {
                start=level+1;
                break;
            }
        }

        if(sum<=limit)
        {
            end=level-1;
            answer=level;
        }
    }
    
    return answer;
}