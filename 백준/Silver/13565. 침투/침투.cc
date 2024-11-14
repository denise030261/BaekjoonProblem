#include <iostream>
#include <cstring>

using namespace std;

int map[1000][1000]; // 0 : white, 1 : black 
bool visited[1000][1000];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
string answer = "NO";
int M, N;

void dfs(int x, int y) {
    if (y == M - 1) {
        answer = "YES";
        return;
    }

    for (int i = 0; i < 4; i++) {
        int move_x = x + dx[i];
        int move_y = y + dy[i];

        if (move_x >= 0 && move_x < N && move_y >= 0 && move_y < M) {
            if (!visited[move_y][move_x] && map[move_y][move_x] == 0) {
                visited[move_y][move_x] = true;
                dfs(move_x, move_y);
                if (answer == "YES") return; 
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        if (map[0][i] == 0 && !visited[0][i]) {
            visited[0][i] = true;
            dfs(i, 0);
            if (answer == "YES") break;
        }
    }

    cout << answer << '\n';
    return 0;
}
