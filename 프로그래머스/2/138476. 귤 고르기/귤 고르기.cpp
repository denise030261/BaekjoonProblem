#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> m;
    for(int i=0;i<tangerine.size();i++)
    {
        m[tangerine[i]]++;
    } 
    
    vector<pair<int, int>> mapVector;
    for (const auto& pair : m) {
        mapVector.push_back(pair);
    }
    
    sort(mapVector.begin(), mapVector.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; 
        });
    
    int sum=0;
    for(auto& it : mapVector)
    {
        //cout << it.first<< ' ' <<it.second<<'\n';
        answer++;
        sum+=it.second;
        if(sum>=k)
            break;
    }
    
    return answer;
}