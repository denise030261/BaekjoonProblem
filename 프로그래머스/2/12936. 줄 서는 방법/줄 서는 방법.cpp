#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long fact(int n)
{
    long long num=1;
    for(int i=n;i>=1;i--)
    {
        num *=i;
    }
    return num;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    int slot=n;
    bool selected[21]={0,};
    for(int i=slot-1;i>=1;i--)
    {
        long long sum =fact(i);
        //cout << k << ' ' <<sum<<'\n';
        for(int j=1;j<=n;j++)
        {
            if(k>sum && !selected[j])
            {
                k-=sum;
               // cout << k <<' ';
            }
            else if(!selected[j])
            {
                //cout <<n<<'\n';
                answer.push_back(j);
                selected[j]=true;
                break;
            }
        }
        //cout << '\n';
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!selected[i])
            {
                answer.push_back(i);
                selected[i]=true;
                break;
            }
    }
    return answer;
}