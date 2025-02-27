// MEC '16 P3 - Getting Good at Programming
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<pair<int, int>> skills[101];

// dp[n][w] = max value attained with first n skills and weight w
// dp[n][w] = max(dp[n-1][w], dp)
int dp[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        int L;
        cin >> L;
        for (int j = 0; j < L; j++) {
            int t, x;
            cin >> t >> x;
            skills[i].push_back({t, x});
        }
        
    }

    for (int i = 1; i <= N; i++) {
        int total_exp = 0;
        int total_time = 0;
        for (auto [t, x] : skills[i]) {
            total_time += t;
            total_exp += x;
            for (int w = T; w >= total_time; w--) {
                dp[i][w] = max(dp[i][w], total_exp + dp[i - 1][w - total_time]);
            }
        }
        for (int w = 0; w <= T; w++) {
            dp[i][w] = max(dp[i][w], dp[i-1][w]);
        }
    }

    cout << dp[N][T] << endl;
}
