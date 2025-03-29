// IOI '00 P1 - Palindrome

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

char str[5002];
int dp[2][5002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> str[i];
    }


    for (int i = 1; i <= N; i++) {
        for (int j = i; j >= 1; j--) {
            if (i == j) {
                dp[1][j] = 0;
                continue;
            } else {
                dp[1][j] = 9999;
            }

            if (str[i] == str[j]) {
                dp[1][j] = dp[0][j + 1];
            } 
            dp[1][j] = min(dp[1][j], dp[0][j] + 1);
            dp[1][j] = min(dp[1][j], dp[1][j + 1] + 1);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][1] << endl;
}
