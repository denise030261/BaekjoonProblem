#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
long long int arr[100001] = { 0, };
long long int tree_max[400001] = { 0, };
long long int tree_min[400001] = { 0, };

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree_max[node] = arr[start];
        tree_min[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;

        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);

        tree_max[node] = max(tree_max[node * 2], tree_max[node * 2 + 1]);
        tree_min[node] = min(tree_min[node * 2], tree_min[node * 2 + 1]);
    }
}

long long int max_query(int node, int start, int end, int r, int l)
{
    if (start > r || end < l)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return tree_max[node];
    }

    int mid = (start + end) / 2;

    long long int left = max_query(node * 2, start, mid, r, l);
    long long int right = max_query(node * 2 + 1, mid + 1, end, r, l);

    return max(left, right);
}

long long int min_query(int node, int start, int end, int r, int l)
{
    if (start > r || end < l)
        return 0;
    if (l <= start && end <= r)
    {
        return tree_min[node];
    }

    int mid = (start + end) / 2;
    long long int left = min_query(node * 2, start, mid, r, l);
    long long int right = min_query(node * 2 + 1, mid + 1, end, r, l);

    if (left == 0)
    {
        return right;
    }
    else if (right == 0)
    {
        return left;
    }
    else
    {
        return min(left, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= 4 * N; i++)
    {
        tree_max[i] = -1;
        tree_min[i] = LONG_MAX;
    }

    build(1, 1, N);

    /*for (int i = 1; i <= 4 * N; i++)
    {
        cout << tree_max[i] << ' ' << tree_min[i] << '\n';
    }*/

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << min_query(1, 1, N, b, a) << ' ' << max_query(1, 1, N, b, a) << '\n';
    }
}