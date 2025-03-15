#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;
    vector<int> denoms;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        denoms.push_back(t);
    }

    for (int i = 0; i < 10001; i++) dp[i] = 1000000;
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (auto x : denoms) {
            if (i >= x) {
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
    }

    cout << dp[x] << endl;
}
