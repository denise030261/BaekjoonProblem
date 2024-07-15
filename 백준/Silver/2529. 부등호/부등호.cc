#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> results;
vector<char> equ(10);
bool visited[10] = { false };

void dfs(int depth, int k, string num) 
{
    if (depth == k + 1) 
    {
        results.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++) 
    {
        if (visited[i]) 
        {
            continue;
        }
        if (depth == 0 || (equ[depth - 1] == '<' && num.back() < (i + '0')) 
            || (equ[depth - 1] == '>' && num.back() > (i + '0')))
        {
            visited[i] = true;
            dfs(depth + 1, k, num + to_string(i));
            visited[i] = false;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) 
    {
        cin >> equ[i];
    }

    dfs(0, k, "");

    sort(results.begin(), results.end());

    cout << results.back() << '\n';
    cout << results.front() << '\n';
}