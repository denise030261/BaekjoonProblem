#include <iostream>

using namespace std;

int extras[7] = { 0, };
bool correct = false;

void dfs(int sum)
{
    if (sum % 7 == 4 || correct)
    {
        correct = true;
        return;
    }

    for (int i = 1; i <= 6;i++)
    {
        if (extras[i] >= 1)
        {
            extras[i]--;
            dfs(sum + i);
            extras[i]++;
        }
        if (correct)
            break;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;

    cin >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        extras[num % 7]++;
    }

    dfs(0);

    if (correct)
        cout << "YES";
    else
        cout << "NO";
}
