#include <iostream>
#include <vector>

using namespace std;

long long tree[4000000] = { 0, };
vector<long long> v;

long long init(int start,int end, int node)
{
	if (start == end)
	{
		return tree[node] = v[start];
	}
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
} // init(start, mid, node * 2) 왼쪽 노드, init(mid + 1, end, node * 2 + 1) 오른쪽 노드

long long sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff)
{
	if (index<start || index>end)
		return;
	tree[node] = tree[node] + diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++)
	{
		long long num;
		cin >> num;
		v.push_back(num);
	}

	init(0, N - 1, 1);

	for (int i = 0; i < M+K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, 0, N - 1, b - 1, c - v[b-1]);
			v[b - 1] = c;
		}
		else
		{
			cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}
}