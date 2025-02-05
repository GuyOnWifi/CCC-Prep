// CCO '15 P4 - Cars on Ice
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N, M;
char grid[2003][2003];
vector<pair<int, int>> dependencies[2003][2003];
int in_degree[2003][2003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(in_degree, -1, sizeof(in_degree));

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c != '.') in_degree[i][j] = 0;
            grid[i][j] = c;
        }
    }

    vector<pair<int, int>> output;
    deque<pair<int, int>> q;

    // right
    for (int i = 0; i < N; i++) {
        int prev = -1;
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.') continue;

            if (prev != -1) {
                dependencies[i][j].push_back({i, prev});
                in_degree[i][prev]++;
            }

            if (grid[i][j] == 'E') {
                prev = j;
            }
        }
    }

    // left
    for (int i = 0; i < N; i++) {
        int prev = -1;
        for (int j = M - 1; j >= 0; j--) {
            if (grid[i][j] == '.') continue;

            if (prev != -1) {
                dependencies[i][j].push_back({i, prev});
                in_degree[i][prev]++;
            }

            if (grid[i][j] == 'W') {
                prev = j;
            }
        }
    }

    // down
    for (int j = 0; j < M; j++) {
        int prev = -1;
        for (int i = 0; i < N; i++) {
            if (grid[i][j] == '.') continue;

            if (prev != -1) {
                dependencies[i][j].push_back({prev, j});
                in_degree[prev][j]++;
            }

            if (grid[i][j] == 'S') {
                prev = i;
            }
        }
    }

    // top
    for (int j = 0; j < M; j++) {
        int prev = -1;
        for (int i = N - 1; i >= 0; i--) {
            if (grid[i][j] == '.') continue;

            if (prev != -1) {
                dependencies[i][j].push_back({prev, j});
                in_degree[prev][j]++;
            }

            if (grid[i][j] == 'N') {
                prev = i;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (in_degree[i][j] == -1) continue;

            if (in_degree[i][j] == 0) {
                output.push_back({i, j});
                q.push_back({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop_front();

        for (auto [x, y] : dependencies[i][j]) {
            in_degree[x][y]--;
            if (in_degree[x][y] == 0) {
                q.push_back({x, y});
                output.push_back({x, y});
            }
        }
    }

    for (auto [x, y] : output) {
        cout << "(" << x << "," << y << ")" << endl;
    }
}
