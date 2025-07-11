#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> s;
bool visited[10]={0,};

void dfs(int index,string numbers,string str)
{
    for(int i=0;i<numbers.length();i++)
    {
        if(visited[i])
            continue;
        
        visited[i]=true;
        str+=numbers[i];
        s.insert(stoi(str));
        dfs(index+1,numbers,str);
        visited[i]=false;
        str.pop_back(); 
    }
}
    
int solution(string numbers) {
    int answer=0;
    
    string str="";
    dfs(0,numbers,str);
    
    bool composite[10000000]={0,};
    for(long int i=2;i<=10000000;i++)
    {
        if(composite[i])
            continue;
        
        for(long int j=2;i*j<=10000000;j++)
        {
            composite[i*j]=true;
        }
    }
    composite[1]=true;
    composite[0]=true;
    
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        //cout <<*it<<'\n';
        if(!composite[*it])
        {
            //cout << *it<<'\n';
            answer++;
        }
    }
    
    return answer;
}