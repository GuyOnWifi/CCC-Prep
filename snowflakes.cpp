#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef unsigned long long ll;

using namespace std;

set<ll> seen;

ll sf_hash(ll sf[6]) {
    ll h = sf[0] + sf[5];
    for (int i = 0; i < 5; i++) {
        h *= sf[i] + sf[i + 1];
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    while (n--) {
        ll snowflake[6];
        for (int i = 0; i < 6; i++) {
            cin >> snowflake[i];
        }

        ll h = sf_hash(snowflake);
        if (seen.count(h)) {
            cout << "Twin snowflakes found." << endl;
            return 0;
        }
        seen.insert(h);
    }

    cout << "No two snowflakes are alike." << endl;

}