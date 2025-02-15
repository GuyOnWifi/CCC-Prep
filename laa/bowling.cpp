// CCC '07 S5 - Bowling for Numbers

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N, K, W;
int pins[30000];
int dp[30000][501];

int recurse(int idx, int left) {
    if (idx < 0) return 0;

    if (dp[idx][left] != -1) return dp[idx][left];


    int op1 = 0;
    if (left > 0) {
        int s = 0;
        for (int i = idx; i > idx - W && i >= 0; i--) {
            s += pins[i];
        }

        op1 = s + recurse(idx - W, left - 1);
    }
    int op2 = recurse(idx - 1, left);

    return dp[idx][left] = max(op1, op2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K >> W;

        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < N; i++) {
            cin >> pins[i];
        }

        cout << recurse(N - 1, K) << endl;
    }
}
