#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    
    int answer = 0;

    map<int, int> left_counts;
    map<int, int> right_counts;
    for(int i=0;i<topping.size();i++) 
    {
        right_counts[topping[i]]++;
    }
    
    for(int i=0;i<topping.size();i++) 
    {
        left_counts[topping[i]]++;
        right_counts[topping[i]]--;
        
        if (right_counts[topping[i]] == 0) 
        {
            right_counts.erase(topping[i]);
        }
        
        if (left_counts.size() == right_counts.size())
        {
            answer++;
        }
    }
    
    return answer;
}