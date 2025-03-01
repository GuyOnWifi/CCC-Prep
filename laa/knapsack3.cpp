#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

ll dp[5001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        ll n, v, p;
        cin >> n >> v >> p;

        // split n into 1, 2, 4, 8;
        int j = 0;
        while (true) {
            ll bound = pow(2, j);
            ll total = pow(2, j + 1) - 1;

            if (total > n) {
                bound = n - (pow(2, j) - 1);
            }
            if (bound == 0) break;
            for (int w = 5000; w >= bound * v; w--) {
                dp[w] = max(dp[w], dp[w - bound * v] + bound * p);
            }
            if (total > n) break;
            j++;
        }
    }

    ll ans = LLONG_MIN;
    for (int i = 0; i < M; i++) {
        int c, f;
        cin >> c >> f;
        ans = max(dp[c] - f, ans);
    }
    cout << ans;
}
