#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    vector<pair<int,pair<int,int>>> v; // 우선순위, plays, 인덱스(-붙어야함)
    map<string,int> sums;
    vector<pair<int,string>> priority;
    
    for(int i=0;i<n;i++)
    {
        sums[genres[i]]+=plays[i];
    }
    
    int m = genres.size();
    for (auto iter = sums.begin() ; iter != sums.end(); iter++)
    {
        priority.push_back({iter->second, iter->first});
    }
    sort(priority.begin(), priority.end(), greater<pair<int,string>>());
    
    map<string,int> mp;
    for(int i=0;i<priority.size();i++)
    {
        mp[priority[i].second] = m;
        m--;
    }
    
    for(int i=0;i<n;i++)
    {
        string name = genres[i];
        v.push_back({mp[name], {plays[i], -i}});
    }
    sort(v.begin(), v.end(), greater<pair<int,pair<int,int>>>());
    
    map<string,int> list;
    for(int i=0;i<n;i++)
    {
        int index = -v[i].second.second;
        if(list[genres[index]]<2)
        {
            answer.push_back(index);
            list[genres[index]]++;
        }
    }
    return answer;
}