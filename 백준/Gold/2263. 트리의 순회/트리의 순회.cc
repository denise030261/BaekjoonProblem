#include <iostream>
#include <vector>

using namespace std;

int N;
int pos[100001] = { 0, };
vector<int> inorder;
vector<int> postorder;

void dfs(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start >= in_end || post_start >= post_end) return;

    int root = postorder[post_end - 1];
    cout << root << ' '; 

    int in_root_idx = pos[root];
    int left_size = in_root_idx - in_start;

    dfs(in_start, in_root_idx, post_start, post_start + left_size);
    dfs(in_root_idx + 1, in_end, post_start + left_size, post_end - 1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;
        inorder.push_back(num);
        pos[inorder[i]] = i; 
    }
    for (int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;
        postorder.push_back(num);
    }

    dfs(0, N, 0, N);
}