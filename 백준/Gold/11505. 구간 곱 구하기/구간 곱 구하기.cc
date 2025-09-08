#include <iostream>
#include <vector>

using namespace std;

long long tree[4000000] = { 0, };
vector<long long> v;

long long init(int node, int start, int end)
{
	if (start == end)
		return tree[node]=v[start];

	int mid = (start + end) / 2;
	return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end))% 1000000007;
}

void update(int node, int start, int end, int index, long long value)
{
	if (index < start || index > end) {
		return;
	}

	// 1. 리프 노드에 도달하면 값을 변경
	if (start == end) {
		tree[node] = value;
		return;
	}

	// 2. 리프를 향해 계속 내려감
	int mid = (start + end) / 2;
	update(node * 2, start, mid, index, value);
	update(node * 2 + 1, mid + 1, end, index, value);

	// 3. 내려갔다 온 후(자식들이 갱신된 후), 부모인 현재 노드의 값을 다시 계산
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
}

long long mul(int node, int start, int end, int left, int right)
{
	if (left > end || start > right)
		return 1;

	if (left <=start && right >= end)
	{
		return tree[node];
	}

	int mid = (start + end) / 2;
	return (mul(node * 2, start, mid,left,right) * mul(node * 2 + 1, mid + 1, end, left, right)) % 1000000007;
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
	init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, 0, N - 1,b-1, c);
			v[b - 1] = c;
		}
		else
		{
			cout << mul(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}
}