#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int M, N;
int grid[1001][1001];
bool memo[1001][1001];

bool dfs(int r, int c) {

    if (r == M && c == N) return true;
    if (r > M || c > N) return false;
    
    if (memo[r][c]) return false;
    memo[r][c] = true;

    int v = grid[r][c];

    // loop through factors
    for (int i = 1; i <= sqrt(v); i++) {
        if (v % i == 0) {
            int j = v / i;
            if (dfs(i, j) || dfs(j, i)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            cin >> grid[r+1][c+1];
        }
    }

    cout << (dfs(1, 1) ? "yes" : "no");
}
