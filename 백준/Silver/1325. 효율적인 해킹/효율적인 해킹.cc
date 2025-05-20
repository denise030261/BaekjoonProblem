#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<int> v[10001];
bool visit[10001];
int result[10001];
int mm = 0;

void bfs(int n) {
    queue<int> q;
    int count = 1;

    q.push(n);
    visit[n] = true;

    while (!q.empty()) {
        int a = q.front();

        q.pop();

        for (int i = 0; i < v[a].size(); i++) {
            int na = v[a][i];

            if (visit[na]) continue;

            q.push(na);
            visit[na] = true;
            count++;
        }
    }

    result[n] = count;
    mm = max(count, mm);
}

void solution() {
    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));

        bfs(i);
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] == mm) {
            cout << i << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    solution();

    return 0;
}