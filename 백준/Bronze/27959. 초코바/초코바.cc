#include <iostream>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    if(N*100>=M)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}