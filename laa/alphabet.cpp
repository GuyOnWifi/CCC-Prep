#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int dp[52];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    // initialize
    s += "{";
    
    for (int i = 0; i < s.size(); i++) {
        dp[i] = s[i] - 'a';
    }

    for (int i = 0; i < s.size(); i++) {
        int smallest = INT_MAX;
        for (int j = i - 1; j >= 0; j--) {
            int req = s[i] - s[j] - 1;
            if (req >= 0) {
                smallest = min(smallest, dp[j] + req);
            }
        }
        dp[i] = min(dp[i], smallest);
    }

    for (int i = 0; i < s.size(); i++) {
        //cout << i << " " << s[i] << " " << dp[i] << endl;
    }

    cout << dp[s.size() - 1] << endl;
}
