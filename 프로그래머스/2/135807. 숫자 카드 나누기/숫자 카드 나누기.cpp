#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool judge(int start, int end,int num, vector<int> arr)
{
    for(int i=start;i<end;i++)
    {
        if(arr[i]%num!=0)
        {
            return false;
        }
    }
    
    return true;
}

bool notjudge(int start, int end,int num, vector<int> arr)
{
    for(int i=start;i<end;i++)
    {
        if(arr[i]%num==0)
        {
            return false;
        }
    }
    
    return true;
}

int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp = a%b;
        a=b;
        b=temp;
    }
    
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int standar = max((arrayA.size()==1?arrayA[0]:gcd(arrayA[1],arrayA[0])),
                      (arrayB.size()==1?arrayB[0]:gcd(arrayB[1],arrayB[0])));
    
    int num=0;
    for(int i = standar;i>=2;i--)
    {
        bool correct=judge(0,arrayA.size(),i,arrayA);
        if(correct)
        {
            num=i;
            bool notDivide=notjudge(0,arrayB.size(),num,arrayB);
            if(notDivide)
            {
                answer=max(answer,num);
                break;
            }
        }

        
        correct=judge(0,arrayB.size(),i,arrayB);
        if(correct)
        {
            num=i;
            bool notDivide=notjudge(0,arrayA.size(),num,arrayA);
            if(notDivide)
            {
                answer=max(answer,num);
                break;
            }
        }
    }
    return answer;
}