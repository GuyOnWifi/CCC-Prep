#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int dp[1002][1002];
char geese[1002];
int geese_points[1002];
char hawks[1002];
int hawks_points[1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> geese[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> geese_points[i];
    }
    
    for (int i = 1; i <= N; i++) {
        cin >> hawks[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> hawks_points[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (geese[i] == hawks[j]) continue;
            if (geese[i] == 'W' && geese_points[i] > hawks_points[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + geese_points[i] + hawks_points[j]);
            } else if (geese[i] == 'L' && geese_points[i] < hawks_points[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + geese_points[i] + hawks_points[j]);
            }
        }
    }
    cout << dp[N][N] << endl;
}
