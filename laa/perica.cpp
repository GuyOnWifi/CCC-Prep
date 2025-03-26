#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

const int MOD = 1000000007;

int N, K;
vector<int> keys;
int dp[100000][51];

int choose(int n, int k) {
    if (dp[n][k] != -1) return dp[n][k];
    if (k == 1) return n;
    if (n == k) return 1;
    if (n == 0) return 0;
    if (k == 0) return 1;
    return dp[n][k] = (choose(n - 1, k) % MOD + choose(n - 1, k - 1) % MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        keys.push_back(a);
    }

    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 51; j++) {
            dp[i][j] = -1;        
        }
    }
    
    choose(100000, 50);
    sort(keys.begin(), keys.end());
    ll ans = 0;

    for (int i = 0; i < keys.size(); i++) {
        ll a = choose(i, K - 1);
        ans += (a * keys[i]) % MOD;
        ans %= MOD;
    }

    cout << ans;

}
