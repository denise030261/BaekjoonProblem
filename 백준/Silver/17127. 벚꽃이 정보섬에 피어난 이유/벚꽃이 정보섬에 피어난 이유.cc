#include <iostream> 
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> bound;
bool visited[10] = { 0, };
int answer = 0;

void dfs(int length, int index)
{
    if (length == 3)
    {
        int sum = 1;
        int result = 0;
        int bound_index = 0;
        for (int i = 0; i < N; i++)
        {
            sum *= v[i];
            if (bound_index < 3)
            {
                if (bound[bound_index] == i)
                {
                    result += sum;
                    sum = 1;
                    bound_index++;
                }
            }
        }
        result += sum;

        answer = max(answer, result);
        return;
    }

    for (int i = index; i < N-1; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            bound.push_back(i);
            dfs(length + 1, i + 1);
            bound.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    dfs(0, 0);

    cout << answer;
}