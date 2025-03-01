// CCC '02 S4 - Bridge Crossing

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

string names[101];
int times[101];

int M, Q;

int dp[101];
int parent[101];

void recurse(int idx) {
    if (idx <= 0) return;
    int l = parent[idx];
    recurse(idx - l);
    for (int i = l - 1; i >= 0; i--) {
        cout << names[idx - i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> Q;

    for (int i = 1; i <= Q; i++) {
        cin >> names[i];
        cin >> times[i];
    }

    for (int i = 1; i <= Q; i++) {
        int slowest = 0;
        int ans = INT_MAX;
        int len = 0;
        // j ppl in queue
        for (int j = 1; j <= M; j++) {
            if (i - j + 1 <= 0) break;
            slowest = max(slowest, times[i - j + 1]);
            int num = dp[i - j] + slowest;
            if (num < ans) {
                ans = num;
                len = j;
            }
        }
        parent[i] = len;
        dp[i] = ans;
    }

    cout << "Total Time: " << dp[Q] << endl;

    recurse(Q);
}
