#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    string str="";
    bool exist=false;
    int move=name.length()-1;
    for(int i=0;i<name.length();i++)
    {
        str+='A';
        
        if(name[i]=='A')
            exist=true;
        
        answer+=min(abs(name[i]-str[i]), abs(26-(name[i]-str[i])));
        
        int index=i+1;
        while(name[index]=='A' && index<name.length())
        {
            index++;
        }
        move=min(move, i+(int)name.length()-index + min(i,(int)name.length()-index));
    }
    
    answer+=move;
    return answer;
}