// VM7WC '16 #4 Gold - Restoring Reputation

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D, I, R;
    cin >> D >> I >> R;

    string a, b;
    cin >> a >> b;

    a = " " + a;
    b = " " + b;

    for (int i = 1; i < 1001; i++) {
        dp[i][0] = i * D;
    }

    for (int i = 1; i < 1001; i++) {
        dp[0][i] = i * I;
    }

    for (int i = 1; i < a.length(); i++) {
        for (int j = 1; j < b.length(); j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int replace = dp[i - 1][j - 1] + R;
                int insert = dp[i][j - 1] + I;
                int del = dp[i - 1][j] + D;

                // cout << replace << " " << insert << " " << del << endl;
                dp[i][j] = min(replace, min(insert, del));
            }
        }
    }

    cout << dp[a.length() - 1][b.length() - 1];

}

