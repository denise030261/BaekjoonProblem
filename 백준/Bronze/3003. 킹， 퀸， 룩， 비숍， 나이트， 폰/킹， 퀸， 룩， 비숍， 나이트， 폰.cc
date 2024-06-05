#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int pieces[6] = { 1,1,2,2,2,8 };

    for (int i = 0; i < 6; i++)
    {
        int num;
        cin >> num;

        pieces[i] = pieces[i] - num;
       
    }

    for (int i = 0; i < 6; i++)
    {
        cout << pieces[i] << ' ';
    }
}
