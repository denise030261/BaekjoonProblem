#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> &v1, vector<int> &v2) {
	if (v1[1] == v2[1])
		return v1[0] < v2[0];
	else 
        return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    long long int answer = 1;
    sort(targets.begin(),targets.end(),compare);
    
    int end = targets[0][1];
    for(int i=1;i<targets.size();i++)
    {
        if(targets[i][0]>=end)
        {
            answer++;
            end = targets[i][1];
        }
    }
    return answer;
}