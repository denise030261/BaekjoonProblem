#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int> answers;
    map<string,string> park;
    for(auto record:records)
    {
        vector<string> v;
        istringstream ss1(record);
        
        string buffer; 
        while(getline(ss1,buffer,' ')){
            v.push_back(buffer);
        }
        
        if(v[2]=="IN")
        {
            park.insert({v[1],v[0]});
        }
        else
        {
            vector<string> times;
            istringstream ss2(park[v[1]]);
        
            string time; 
            while(getline(ss2,time,':')){
                times.push_back(time);
            }
            int inHour = stoi(times[0]);
            int inMinute = stoi(times[1]);
            
            times.clear();
            istringstream ss3(v[0]);
            while(getline(ss3,time,':')){
                times.push_back(time);
            }
            int outHour = stoi(times[0]);
            int outMinute = stoi(times[1]);
            
            if(outMinute<inMinute)
            {
                outHour--;
                outMinute+=60;
            }
            int totalTime = (outHour-inHour)*60 + (outMinute-inMinute);
            answers[v[1]]+=totalTime;
            
            park.erase(v[1]);
        }
    }
    
    for (auto iter = park.begin() ; iter !=  park.end(); iter++)
	{
        vector<string> times;
            istringstream ss4(iter->second);
        
            string time; 
            while(getline(ss4,time,':')){
                times.push_back(time);
            }
            int inHour = stoi(times[0]);
            int inMinute = stoi(times[1]);
            
            times.clear();
            int outHour = 23;
            int outMinute = 59;
            
            if(outMinute<inMinute)
            {
                outHour--;
                outMinute+=60;
            }
            int totalTime = (outHour-inHour)*60 + (outMinute-inMinute);
            answers[iter->first]+=totalTime;
	}
    
    for (auto iter = answers.begin() ; iter !=  answers.end(); iter++)
	{
        float totalTime = iter->second;
        if(totalTime<=fees[0])
        {
            answer.push_back(fees[1]);
        }
        else
        {
            totalTime-=fees[0];
            answer.push_back(fees[1]+ ceil(totalTime/fees[2])*fees[3]); 
        }
	}

    return answer;
}