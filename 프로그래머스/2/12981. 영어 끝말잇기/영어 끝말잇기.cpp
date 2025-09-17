#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,int> m;
    int sum=0;
    
    m[words[0]]++;
    char ch = words[0][words[0].length()-1];
    sum++;
    bool correct=true;
    for(int i=1;i<words.size();i++)
    {
        sum++;
        if(words[i][0]==ch && m[words[i]]==0)
        {
            m[words[i]]++;
            ch = words[i][words[i].length()-1];
        }
        else
        {
            correct=false;
            break;
        }
    }
    
    if(correct)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if(sum%n==0)
    {
        answer.push_back(n);
        answer.push_back(sum/n);
    }
    else
    {
        answer.push_back(sum%n);
        answer.push_back((sum/n)+1);
    }
    return answer;
}