#include <iostream>
#include <vector>
#include <numeric> // std::accumulate, std::iota (C++11) 등 사용 가능
#include <algorithm> // std::max 사용

using namespace std;

int root[30001];
int candy[30001];
int group_size[30001]; // 각 그룹의 아이 수
long long group_candy[30001]; // 각 그룹의 사탕 총합 (long long 주의!)
int dp[3001]; // 냅색 DP 배열 (크기는 K)

// Find 함수 (경로 압축 포함)
int Find(int x) {
    if (root[x] == x) {
        return x;
    }
    // 경로 압축: 루트를 찾는 과정에서 만나는 모든 노드의 부모를 최종 루트로 직접 연결
    return root[x] = Find(root[x]);
}

// Union 함수 (기본적인 Union)
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        // 작은 번호의 루트를 기준으로 합침 (항상 그럴 필요는 없지만 일관성을 위해)
        if (x < y) {
            root[y] = x;
        } else {
            root[x] = y;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    // 초기화
    for (int i = 1; i <= N; ++i) {
        cin >> candy[i];
        root[i] = i;        // 처음에는 자기 자신이 루트
        group_size[i] = 1;  // 처음 그룹 크기는 1
        group_candy[i] = candy[i]; // 처음 사탕 수는 자기 자신
    }

    // 친구 관계 입력받아 Union 연산 수행
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    // 그룹 정보 계산: 각 아이의 루트를 찾아 해당 루트에 정보 합산
    // Union 연산 시 실시간으로 합산하는 것이 더 효율적이지만, 이 방법도 가능
    fill(group_size + 1, group_size + N + 1, 0); // group_size 초기화
    fill(group_candy + 1, group_candy + N + 1, 0); // group_candy 초기화
    for(int i = 1; i <= N; ++i) {
        int r = Find(i); // 아이 i의 최종 루트 찾기
        group_size[r]++;
        group_candy[r] += candy[i];
    }
    // 이 방식 대신, Union 할 때 합쳐지는 그룹의 정보를 합치는 것이 더 효율적
    // 아래는 Union 시 합산하는 방식 (참고)
    /*
    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            if (x < y) {
                root[y] = x;
                group_size[x] += group_size[y];
                group_candy[x] += group_candy[y];
            } else {
                root[x] = y;
                group_size[y] += group_size[x];
                group_candy[y] += group_candy[x];
            }
        }
    }
    */


    // 0/1 냅색 DP
    for (int i = 1; i <= N; ++i) {
        // i가 자기 그룹의 대표(루트)이고, 그룹에 멤버가 있을 때만 처리
        if (root[i] == i && group_size[i] > 0) {
            int current_group_size = group_size[i];
            long long current_group_candy = group_candy[i];

            // K명 미만으로 울려야 하므로, 무게 한도는 K-1
            // j를 큰 값부터 줄여나가야 0/1 냅색이 됨
            for (int j = K - 1; j >= current_group_size; --j) {
                // 현재 그룹을 포함하는 경우와 포함하지 않는 경우 중 최대 사탕 수 선택
                dp[j] = max(dp[j], dp[j - current_group_size] + (int)current_group_candy); // dp 배열은 int로 충분할 수 있음 (문제 조건 확인)
            }
        }
    }

    // 최대 K-1명을 울릴 때 얻을 수 있는 최대 사탕 수 출력
    cout << dp[K - 1] << endl;

    return 0;
}