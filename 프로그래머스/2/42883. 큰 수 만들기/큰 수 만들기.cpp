#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> remove;
    for(int i=0;i<number.size();i++)
    {
        int num=number[i]-'0';
        bool possible=true;
        for(int j=i+1;j<number.size();j++)
        {
            if(k==0)
                break;
            
            if(num<number[j]-'0')
            {
                if(k>=j-i)
                {
                    possible=false;
                    k-=j-i;
                    i=j-1;
                }
                
                break;
            }
        }
        
        if(k==1 && i==number.size()-1)
            break;
            
        if(possible)
        {
            answer+=number[i];
        }
        
    }
    
    return answer;
}