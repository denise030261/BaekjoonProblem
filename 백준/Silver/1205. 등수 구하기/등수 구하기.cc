#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int N, score, P; // N은 현재 점수 갯수, score은 새로운 점수, P는 랭킹리스트
    vector<long long int> v;
    cin >> N >> score >> P;
    
    for (int i = 0; i < N; i++)
    {
        long long int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(),greater<int>());

    long long int same = -1;
    for (int i = 1; i <= P; i++)
    {
        if (i - 1 >= v.size())
        {
            if (same == -1)
            {
                cout << i;
            }
            else
            {
                cout << same;
            }
            return 0;
        }

        if (score > v[i-1])
        {
            if (same == -1)
            {
                cout << i;
                return 0;
            }
            else
            {
                cout << same;
                return 0;
            }
        }
        else if (score == v[i - 1] && same==-1)
        {
            same = i;
        }
    }

    cout << -1;
    return 0;
}