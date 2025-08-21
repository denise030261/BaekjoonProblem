#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> counts;

    for (int w : weights) 
    {
        counts[w]++;
    }
    
    for (auto const& [w, count] : counts) 
    {
        if (count >= 2) 
        {
            answer += (long long)count * (count - 1) / 2;
        }

        if (counts.count(w * 3 / 2.0)) 
        {
            if (w * 3 % 2 == 0) 
            { 
                answer += (long long)count * counts[w * 3 / 2.0];
            }
        }
        
        if (counts.count(w * 2 / 1.0)) 
        {
            answer += (long long)count * counts[w * 2 / 1.0];
        }

        if (counts.count(w * 4 / 3.0)) 
        {
            if (w * 4 % 3 == 0) 
            { 
                answer += (long long)count * counts[w * 4 / 3.0];
            }
        }
    }
    return answer;
}