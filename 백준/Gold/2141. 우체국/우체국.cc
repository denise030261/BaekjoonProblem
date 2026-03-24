#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long int, long long int>> v;
long long int answer_num = LLONG_MAX;
long long int answer = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    long long int sum = 0;
    for (int i = 0; i < N; i++)
    {
        long long int X, A;
        cin >> X >> A;
        v.push_back({ X,A });
        sum += A;
    }

    sort(v.begin(), v.end());

    sum++;
    sum /= 2;
   
    long long int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += v[i].second;
        if (total >= sum)
        {
            cout << v[i].first;
            return 0;
        }

    }
    cout << v[v.size() - 1].first;
}