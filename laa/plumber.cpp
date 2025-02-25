// CCC '04 S5 - Super Plumber

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int M, N;
char grid[101][101];
int visited[101][101][3];

// 0 for up, 1, for down, 2 for right
int recurse(int x, int y, int coins, int dir) {

    if (x < 0 || x >= M) return -1;
    if (y < 0 || y >= N) return -1;

    if (visited[x][y][dir] != -1) {
        if (coins <= visited[x][y][dir]) {
            return -1;
        }
    }

    char c = grid[x][y];
    if (c == '*') return -1;

    if (c >= '1' && c <= '9') {
        coins += c - '0';
    }

    if (x == M - 1 && y == N - 1) return coins;

    int res = 0;
    if (dir == 0) {
        res = max(res, recurse(x - 1, y, coins, 0));
        res = max(res, recurse(x, y + 1, coins, 2));
    } else if (dir == 1) {
        res = max(res, recurse(x + 1, y, coins, 1));
        res = max(res, recurse(x, y + 1, coins, 2));
    } else {
        res = max(res, recurse(x - 1, y, coins, 0));
        res = max(res, recurse(x + 1, y, coins, 1));
        res = max(res, recurse(x, y + 1, coins, 2));
    }
    visited[x][y][dir] = coins;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> M >> N;
        if (M == 0 && N == 0) break;

        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
            }
        }

        cout << recurse(M - 1, 0, 0, 'U') << endl;
        continue;
    }

}