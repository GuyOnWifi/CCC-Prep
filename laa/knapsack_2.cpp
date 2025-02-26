// Educational DP Contest AtCoder D - Knapsack 1

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N, W;
ll weights[101];
ll values[101];
ll memo[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;
    
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }

    for (int i = 1; i < 100001; i++) {
        memo[i] = 1000000001;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 100000; j >= 0; j--) {
            ll with = 1000000001;
            if (j >= values[i]) {
                with = memo[j - values[i]] + weights[i];
            }
            ll without = memo[j];
            memo[j] = min(with, without);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 100001; i++) {
        if (memo[i] <= W) {
            ans = i;
        }
    }
    cout << ans;
}
