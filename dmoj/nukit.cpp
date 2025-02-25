#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int moves[5][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};

int memo[31][31][31][31];

bool winner(int a, int b, int c, int d) {
    if (a < 0 || b < 0 || c < 0 || d < 0) return true;

    if (memo[a][b][c][d]) return true;

    bool res = false;
    for (int i = 0; i < 5; i++) {
        auto move = moves[i];
        res = res || !winner(a - move[0], b - move[1], c - move[2], d - move[3]);
    }
    memo[a][b][c][d] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (;n>0;n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (winner(a, b, c, d)) {
            cout << "Patrick\n";
        } else {
            cout << "Roland\n";
        }
    }
}