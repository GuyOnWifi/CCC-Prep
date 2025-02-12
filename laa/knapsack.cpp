// Educational DP Contest AtCoder D - Knapsack 1

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N, W;
ll weights[101];
ll values[101];
ll memo[101][100001];

ll recurseMemo(int idx, int w) {
    if (memo[idx][w] != -1) {
        return memo[idx][w];
    }

    if (idx == 0) {
        memo[idx][w] = 0;
        return 0;
    }

    if (weights[idx] > w) {
        memo[idx][w] = recurseMemo(idx - 1, w);
        return memo[idx][w];
    }

    memo[idx][w] = max(recurseMemo(idx - 1, w), values[idx] + recurseMemo(idx - 1, w - weights[idx]));
    return memo[idx][w];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;
    
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << recurseMemo(N, W);
}
