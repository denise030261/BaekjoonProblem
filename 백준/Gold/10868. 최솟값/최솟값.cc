#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
long int arr[100001] = { 0, };
long int tree[400001] = { 0, };

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;

        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

long int query(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    long int left = query(node * 2, start, mid, l, r);
    long int right = query(node * 2 + 1, mid + 1, end, l, r);

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

    for (int i = 0; i <= 4 * N; i++)
    {
        tree[i] = LONG_MAX;
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    build(1, 1, N);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, N, a, b) << '\n';
    }
}