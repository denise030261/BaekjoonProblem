#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int L,P;
    vector<int> v;
    cin >> L >> P;
    
    int num;
    for(int i=0;i<5;i++)
    {
        cin >> num;
        v.push_back(num);
    }
    
    for(int i=0;i<5;i++)
    {
        cout << v[i] - L*P <<' ';
    }
}