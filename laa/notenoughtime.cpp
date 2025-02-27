// DMOPC '14 Contest 3 P6 - Not Enough Time!

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

// dp[n][w]
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        int p_poor, v_poor, p_avg, v_avg, p_good, v_good;
        cin >> p_poor >> v_poor >> p_avg >> v_avg >> p_good >> v_good;
        
        for (int w = T; w >= 0; w--) {
            if (w >= p_good) {
                int a = max(v_avg + dp[w - p_avg], v_good + dp[w - p_good]);
                int b = max(a, v_poor + dp[w - p_poor]);
                dp[w] = max(dp[w], b);
            } else if (w >= p_avg) {
                int a = max(v_avg + dp[w - p_avg], v_poor + dp[w - p_poor]);
                dp[w] = max(dp[w], a);
            }  else if (w >= p_poor) {
                dp[w] = max(dp[w], v_poor + dp[w - p_poor]);
            } 
        }
    }

    cout << dp[T] << endl;
}
