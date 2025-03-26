#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int ans = 0;
    for (int i = 1; i < a.length(); i++) {
        for (int j = 1; j < b.length(); j++) {
            cout << j << endl;
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    
}

