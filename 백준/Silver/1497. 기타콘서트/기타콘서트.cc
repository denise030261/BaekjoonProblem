#include <iostream> 
#include <vector> 
#include <climits>

using namespace std;

long long int guitar = LLONG_MAX;
long long int song = -1;
int N, M;
vector<long long int> v;

long long int count(long long int num)
{
    long long int one = 0;
    for (int i = 0; i < M; i++)
    {
        if (num & ((long long int)1 << i))
        {
            one++;
        }
    }
    return one;
}

void dfs(int index, long long int sum, long long int total) // sum은 가능한 곡 수, total은 기타 수  
{
    long long int play = count(sum);
    //cout << sum << ' ' << play << ' ' << song <<' '<< guitar <<' '<< total << '\n';
    if (song < play)
    {
        song = play;
        guitar = total;
    }
    else if (song == play)
    {
        guitar = min(total, guitar);
    }

    for (int i = index; i < N; i++)
    {
        dfs(i + 1, sum | v[i], total + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;

        long long int s = 0;
        for (int j = 0; j < M; j++)
        {
            if (str2[j] == 'Y')
            {
                s |= ((long long int)1 << M - 1 - j);
            }
        }
        v.push_back(s);
    }

    dfs(0, 0, 0);

    if (guitar == 0)
    {
        cout << -1;
    }
    else
    {
       cout << guitar;
    }
}