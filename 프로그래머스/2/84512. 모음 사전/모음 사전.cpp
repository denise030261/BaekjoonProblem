#include <string>
#include <vector>
#include <iostream>

using namespace std;

char ch[5]={'A', 'E', 'I', 'O','U'};

int answer = 0;
string compare="";
bool correct=false;

void dfs(string str,int index, int sum)
{
    if(str.length()>5 || correct)
        return;
    
    if(str==compare)
    {
        correct=true;
        return;
    }
    
    for(int i=0;i<5;i++)
    {
        if(!correct && str.length()+1<=5)
        {
            answer++;
            //cout << str+ch[i] << " : "<<answer<<'\n';
            dfs(str+ch[i], i,sum+1);
        }
    }
}

int solution(string word) {
    string str="";
    compare=word;
    dfs(str,0,0);
    return answer;
}