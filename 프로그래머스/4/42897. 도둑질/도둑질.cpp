#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    if(money.size()==3)
    {
        answer = max(money[0],max(money[1],money[2]));
        return answer;
    }
    vector<int> v1(money.size());
    vector<int> v2(money.size());
    v1[0]=0; v1[1]=money[1]; v1[2]=max(v1[1], money[2]);
    v2[0]=money[0]; v2[1]=max(v2[0], money[1]);
    for(int i=3;i<money.size();i++)
    {
        v1[i]=max(v1[i-1],v1[i-2]+money[i]);
    }
    for(int i=2;i<money.size()-1;i++)
    {
        v2[i]=max(v2[i-1],v2[i-2]+money[i]);
    }
    answer = max(v1[money.size()-1], v2[money.size()-2]);
    return answer;
}