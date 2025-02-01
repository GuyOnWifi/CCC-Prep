#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

char grid[101][101];
string word;
int r, c;
int matches = 0;

void crossword(int x, int y, int dx, int dy, bool turned, int idx, bool start) {
    if (x < 0 || x > c - 1 || y < 0 || y > r - 1) return;
    if (word[idx] != grid[y][x]) return;
    if (idx == word.size() - 1) {
        matches++;
        return;
    }
    crossword(x + dx, y + dy, dx, dy, turned, idx + 1, false);
    if (!turned && !start) {
        crossword(x, y, -dy, dx, true, idx, false);
        crossword(x, y, dy, -dx, true, idx, false);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> word >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            // Loop through all possible directions
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    crossword(x, y, dx, dy, false, 0, true);
                }
            }
        }
    }
    cout << matches;
}
