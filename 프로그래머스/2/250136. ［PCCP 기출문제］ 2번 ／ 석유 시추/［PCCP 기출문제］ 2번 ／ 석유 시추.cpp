#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool visited[501][501];
int oil_component_id[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> current_land;
vector<int> component_sizes;

int current_component_size;
int current_component_id;

void dfs(int y, int x) {
    visited[y][x] = true;
    oil_component_id[y][x] = current_component_id;
    current_component_size++;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < current_land.size() && nx >= 0 && nx < current_land[0].size() &&
            !visited[ny][nx] && current_land[ny][nx] == 1) {
            dfs(ny, nx);
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    current_land = land;
    int R = land.size();
    int C = land[0].size();

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            visited[i][j] = false;
            oil_component_id[i][j] = 0;
        }
    }
    component_sizes.clear();
    component_sizes.push_back(0); 

    current_component_id = 1;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (current_land[i][j] == 1 && !visited[i][j]) {
                current_component_size = 0;
                dfs(i, j);
                component_sizes.push_back(current_component_size);
                current_component_id++;
            }
        }
    }
    
    for (int j = 0; j < C; ++j) {
        set<int> unique_oil_ids;
        for (int i = 0; i < R; ++i) {
            if (current_land[i][j] == 1) {
                unique_oil_ids.insert(oil_component_id[i][j]);
            }
        }

        int current_column_oil_sum = 0;
        for (int id : unique_oil_ids) {
            current_column_oil_sum += component_sizes[id];
        }
        answer = max(answer, current_column_oil_sum);
    }

    return answer;
}