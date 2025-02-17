#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N;

// R true, W false
bool grid[10][10];

void reduce_grid() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (grid[i][j]) {
                grid[i][j] = !grid[i][j];
                grid[i + 1][j] = !grid[i + 1][j];
                grid[i][j + 1] = !grid[i][j + 1];
                grid[i + 1][j + 1] = !grid[i + 1][j + 1];
            }
        }
    }
}

string convert_grid() {
    string s = "";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                s += 'R';
            } else {
                s += 'W';
            }
        }
    }
    return s;
}

unordered_map<string, int> freq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int G;
    cin >> G;
    while (G--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                if (c == 'R') {
                    grid[i][j] = true;
                } else {
                    grid[i][j] = false;
                }
            }
        }
        reduce_grid();
        string s = convert_grid();

        freq[s]++;
    }

    int ans = 0;
    for (auto [k, v] : freq) {
        ans += v * (v - 1) / 2;
    }
    cout << ans << endl;
}   
