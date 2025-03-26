#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int a[100001];
int b[100002];

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= N; i++) {
        cin >> b[i];
    }

    ll prev_0 = 1;
    ll prev_1 = 0;
    for (int i = 1; i < N; i++) {
        ll new_prev_0 = (prev_0 * (a[i] + b[i])) % MOD + (prev_1 * (a[i] + b[i] - 1)) % MOD;
        ll new_prev_1 = (prev_0 * b[i + 1]) % MOD + (prev_1 * b[i + 1]) % MOD;
        prev_0 = new_prev_0;
        prev_1 = new_prev_1;
    }

    cout << max(prev_0, prev_1) << endl;
}
