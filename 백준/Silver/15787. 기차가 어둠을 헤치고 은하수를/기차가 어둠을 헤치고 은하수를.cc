#include <iostream> 
#include <map> 
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    int arr[100001] = { 0, };
    map<int, int> answer;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int order, train;
        cin >> order >> train;
        if (order == 1 || order == 2)
        {
            int seat;
            cin >> seat;

            if (order == 1)
            {
                arr[train] |= (1 << seat);
            }
            else
            {
                arr[train] &= ~(1 << seat);
            }
        }
        else if(order==3)
        {
            arr[train] <<= 1;
            arr[train] &= ~(1 << 21);
        }
        else
        {
            arr[train] >>= 1;
            arr[train] &= ~(1 << 0);
        }

    }

    for (int i = 1; i <= N; i++)
    {
        answer[arr[i]]++;
    }

    cout << answer.size();
}