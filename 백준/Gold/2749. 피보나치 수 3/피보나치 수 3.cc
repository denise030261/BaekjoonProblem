#include <iostream>
#include <vector>
#define DIV  1000000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int N;
    cin >> N;

    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    int period = -1;
    for (int i = 2; ; i++)
    {
        int sum = (v[i - 1] + v[i - 2]) % DIV;
        v.push_back(sum);

        if (sum == 1)
        {
            period = i - 1;
            if (v[i - 1] == 0)
            {
                break;
            }
        }
    }

    cout << v[N % period];
}