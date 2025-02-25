#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int ans = 0;
    cin >> N;

    while (N > 1) {
        for (int i = 2; i <= N; i++)
            if (N % i == 0) {
                int n = N/i;
                N -= n;
                ans += N/n;
                break;
            }
    }
    cout << ans;
}