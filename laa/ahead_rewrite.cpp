#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

char grid[6][6];
vector<pair<int, int>> targets;
pair<int, int> start;
bool ans[5];
bool visited[6][6][4];

void dfs(int x, int y, int d) {
    // out of bounds
    if (x < 0 || x >= 6 || y < 0 || y >= 6) return;

    // if already visited
    if (visited[x][y][d]) return;
    visited[x][y][d] = true;

    char c = grid[x][y];
    if (c == '.') return;
    if (c == 'T') {
        for (int i = 0; i < 5; i++) {
            if (targets[i].first == x && targets[i].second == y) ans[i] = true;
        }
        return;
    }
    if ((x < 1 || x > 4 || y < 1 || y > 4) && c != 'S') return;
    if (d < 0 || d > 3) return;

    // calculate which direction to go
    int x1 = x;
    int y1 = y;
    int dx = 0;
    int dy = 0;
    if (d == 0) dy = -1;
    if (d == 1) dx = 1;
    if (d == 2) dy = 1;
    if (d == 3) dx = -1;
    set<char> seen;

    x1 += dx;
    y1 += dy;
    while (x1 >= 0 && x1 < 6 && y1 >= 0 && y1 < 6) {
        seen.insert(grid[x1][y1]);
        x1 += dx;
        y1 += dy;
    }

    if (c == 'S' && !seen.count('U')) return;
    if (seen.count('U')) dfs(x, y - 1, d);
    if (seen.count('D')) dfs(x, y + 1, d);
    if (seen.count('L')) dfs(x - 1, y, d);
    if (seen.count('R')) dfs(x + 1, y, d);
    if (seen.count('C')) dfs(x, y, (d + 1) % 4);
    if (seen.count('B')) dfs(x, y, (d + 3) % 4); // modulo magik

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 0; tc < 10; tc++) {

        // reset variables
        targets.clear();
        memset(ans, false, sizeof(ans));
        memset(visited, false, sizeof(visited));


        for (int y = 0; y < 6; y++) {
            for (int x = 0; x < 6; x++) {
                char c;
                cin >> c;
                
                if (c == 'T') targets.pb({x, y});
                if (c == 'S') start = {x, y};
                grid[x][y] = c;

            }
        }

        dfs(start.first, start.second, 0);
        for (int i = 0; i < 5; i++) {
            if (ans[i]) {
                cout << "T";
            } else {
                cout << "F";
            }
        }
        cout << endl;
    }
}
