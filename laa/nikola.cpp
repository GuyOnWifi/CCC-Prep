// COCI '07 Regional #2 Nikola

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int dp[1001][1001];
int fee[1001];
int N;

int recurse(int sq, int last) {
    if (sq <= 0 || sq > N) return 100000000;
    if (sq == N) return fee[N];
    if (dp[sq][last] != -1) {
        return dp[sq][last];
    }
    dp[sq][last] = fee[sq] + min(recurse(sq - last, last), recurse(sq + last + 1, last + 1));
    return dp[sq][last];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> fee[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << recurse(2, 1);
} 
