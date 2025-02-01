#include <bits/stdc++.h>
#define long long ll

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, k;
    cin >> m >> n >> k;

    map<int, int> row, col;

    for (;k > 0; k--) {
        char t;
        int n;
        cin >> t >> n;
        if (t == 'R') {
            row[n] += 1;
        } else {
            col[n] += 1;
        }
    }

    int row_count = 0;
    for (const auto& x : row) {
        if (x.second % 2 == 1) row_count += 1;
    }

    int col_count = 0;
    for (const auto& x : col) {
        if (x.second % 2 == 1) col_count += 1;
    }

    cout << row_count * n + col_count * m - 2 * row_count * col_count;
}