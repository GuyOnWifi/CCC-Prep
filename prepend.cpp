#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        int needed = k - (n % k);
        int mod = 10 % k;

        while (needed != 0) {
            if (mod < needed) {
                cout << "NO\n";
                break;
            }
            needed %= mod;
            mod *= mod;
        }
        if (needed == 0) cout << "YES\n";

    }
}
