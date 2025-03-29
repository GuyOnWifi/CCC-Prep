// RGPC '17 P5 - Scrabble Nuts

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

char a[10001];
char b[10001];
int dp[2][10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= M; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < 10001; i++) {
        dp[0][i] = i;
        dp[1][i] = 99999;
    }

    for (int i = 1; i <= N; i++) {
        dp[1][0] = i;
        for (int x = 1; x < 10001; x++) {
            dp[1][x] = 99999;
        }
        for (int j = 1; j <= M; j++) {
            if (a[i] == b[j]) {
                dp[1][j] = dp[0][j - 1];
            }
            dp[1][j] = min(dp[1][j], dp[0][j] + 1);
            dp[1][j] = min(dp[1][j], dp[1][j - 1] + 1);
            dp[1][j] = min(dp[1][j], dp[0][j - 1] + 1);
        }
        swap(dp[0], dp[1]);
    }

    int sum = 0;
    for (int i = 1; i < M; i++) {
        sum += dp[0][i];
    }
    cout << sum << endl;
}
