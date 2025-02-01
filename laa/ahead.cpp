#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

char grid[6][6];
pair<int, int> start;
vector<pair<int, int>> target;
bool ans[5];
bool visited[6][6][4];

// 0 for U, 1 for R, 2 for D, 3 for L (clockwise)
void dfs(int x, int y, int dir) {
    if (x < 0 || x >= 6 || y < 0 || y >= 6) return;

    if (visited[x][y][dir]) return;
    visited[x][y][dir] = true;

    char curr = grid[y][x];

    if (curr == '.') return;
    if (curr == 'T') {
        auto coord = make_pair(x, y);
        for (int i = 0; i < target.size(); i++) {
            if (coord == target[i]) {
                ans[i] = true;
            }
        }
        return;
    }

    set<char> seen;
    int x1 = x, y1 = y, x_change = 0, y_change = 0;

    if (dir == 0) y_change = -1;
    if (dir == 1) x_change = 1;
    if (dir == 2) y_change = 1;
    if (dir == 3) x_change = -1;

    x1 += x_change;
    y1 += y_change;
    while (x1 >= 0 && x1 < 6 && y1 >= 0 && y1 < 6) {
        seen.insert(grid[y1][x1]);

        x1 += x_change;
        y1 += y_change;
    }
    // must step into the board
    
    if (curr == 'S' && !seen.count('U')) return;
    
    if (seen.count('U')) dfs(x, y - 1, dir);
    if (seen.count('D')) dfs(x, y + 1, dir);
    if (seen.count('L')) dfs(x - 1, y, dir);
    if (seen.count('R')) dfs(x + 1, y, dir);
    if (seen.count('C')) dfs(x, y, (dir + 1) % 4);
    if (seen.count('B')) dfs(x, y, (dir + 3) % 4); // modulo "hack"

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // each test case
    for (int tc = 0; tc < 10; tc++) {

        // reset variables
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 5; i++) ans[i] = false;
        target.clear();

        for (int y = 0; y < 6; y++) {
            for (int x = 0; x < 6; x++) {
                char c;
                cin >> c;
                if (c == 'S') {
                    start = make_pair(x, y);
                } else if (c == 'T') {
                    target.pb(make_pair(x, y));
                }
                grid[y][x] = c;
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
