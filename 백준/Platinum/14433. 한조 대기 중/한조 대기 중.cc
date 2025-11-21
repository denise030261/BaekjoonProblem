#include <iostream>
#include <vector>

using namespace std;

vector<int> my[301];
vector<int> enemy[301];
bool my_selected[301] = { 0, };
bool enemy_selected[301] = { 0, };
int my_trol = 0;
int enemy_trol = 0;
int my_assign[301] = { 0, };
int enemy_assign[301] = { 0, };
int N, M, K1, K2;

bool my_dfs(int current)
{
    for (int i = 0; i < my[current].size(); i++)
    {
        int character = my[current][i];
        if (my_selected[character])
            continue;

        my_selected[character] = true;
        if (my_assign[character] == 0 || my_dfs(my_assign[character]))
        {
            my_assign[character] = current;
            return true;
        }
    }

    return false;
}

bool enemy_dfs(int current)
{
    for (int i = 0; i < enemy[current].size(); i++)
    {
        int character = enemy[current][i];
        if (enemy_selected[character])
            continue;

        enemy_selected[character] = true;
        if (enemy_assign[character] == 0 || enemy_dfs(enemy_assign[character]))
        {
            enemy_assign[character] = current;
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K1 >> K2;

    for (int i = 0; i < K1; i++)
    {
        int a, b;
        cin >> a >> b;
        my[a].push_back(b);
    }
    for (int i = 0; i < K2; i++)
    {
        int a, b;
        cin >> a >> b;
        enemy[a].push_back(b);
    }

    for (int i = 1; i <= N; i++)
    {
        fill(my_selected, my_selected + 301, false);
        if (my_dfs(i))
            my_trol++;

        //cout << i << " : " << my_trol << '\n';
    }

    for (int i = 1; i <= N; i++)
    {
        fill(enemy_selected, enemy_selected + 301, false);
        if (enemy_dfs(i))
            enemy_trol++;
    }

    if (my_trol < enemy_trol)
    {
        cout << "네 다음 힐딱이";
    }
    else
    {
        cout << "그만 알아보자";
    }
}