#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

bool isPrime(long long num)
{
    for(long long i=2;i*i<=num;i++)
    {
        if(num%i==0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str="";
    while(n!=0)
    {
        str+=n%k+'0';
        n/=k;
    }
    reverse(str.begin(),str.end());
    
    vector<long long> v;
    
    istringstream iss(str);             
    string buffer;                      
 
    vector<string> result;
 
    while (getline(iss, buffer, '0')) {
        if(buffer!="1" && buffer!="")
            v.push_back(stoll(buffer));               
    }
    
    for(int i=0;i<v.size();i++)
    {  
        if(isPrime(v[i]))
            answer++;
    }

    return answer;
}