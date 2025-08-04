#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answers;
    for(int i=0;i<places.size();i++)
    {
        int answer=1;
        
        vector<string> place = places[i];
        vector<pair<int,int>> people;
        for(int j=0;j<place.size();j++)
        {
            for(int k=0;k<place[j].length();k++)
            {
                if(place[j][k]=='P')
                {
                    people.push_back({j,k});
                }
            }
        }
        
        for(int j=0;j<people.size();j++)
        {
            int p1X = people[j].first;
            int p1Y = people[j].second;
            for(int k=j+1;k<people.size();k++)
            {
                int p2X = people[k].first;
                int p2Y = people[k].second;

                if(abs(p1X-p2X)+abs(p1Y-p2Y)<=1)
                {
                    answer=0;
                }
                else if(abs(p1X-p2X)+abs(p1Y-p2Y)==2)
                {
                    if(p1X==p2X && place[p1X][(p1Y+p2Y)/2]!='X')
                    {
                        answer=0;
                    }
                    else if(p1Y==p2Y && place[(p1X+p2X)/2][p1Y]!='X')
                    {
                        answer=0;
                    }
                    else if(p1X!=p2X &&p1Y!=p2Y && (place[p1X][p2Y]!='X' || place[p2X][p1Y]!='X'))
                    {
                        answer=0;
                    }
                }
                
                if(answer==0)
                    break;
            }
            
            if(answer==0)
                break;
        }
        
        if(answer==0)
        {
            answers.push_back(0);
        }
        else
        {
            answers.push_back(1);
        }
    }
    return answers;
}