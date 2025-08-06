#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    
    for(int i=0;i<elements.size();i++)
    {
        int sum=0;
        for(int j=0;j<elements.size();j++)
        {
            sum+=elements[(i+j)%elements.size()];
            s.insert(sum);
            //cout << sum<<'\n';
        }
    }
    
    answer=s.size();
    return answer;
}