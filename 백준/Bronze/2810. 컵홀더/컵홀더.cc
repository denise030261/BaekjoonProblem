#include <iostream>

using namespace std;

int N;
char arr[51];

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i=0;i<N;i++) 
        cin >> arr[i];
    
    int cnt=1;
    int temp=0;
    
    for(int i=0;i<N;i++) 
    {
        if(arr[i]=='S')
            cnt++;
        else 
        {
            temp++;
            if(temp==2) 
            {
                temp=0;
                cnt++;
            }
        }
    }

    if(cnt>N) 
        cout << N;
    else 
        cout << cnt;
}