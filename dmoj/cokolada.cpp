#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    long long bar = (int) ceil(log2(k));
    long long bar_size = pow(2, bar);
    unsigned long long remain = bar_size - k;

    if (remain == 0) {
        cout << bar_size << " 0";
        return 0;
    }

    int i = 0;
    for (;i < 64; i++) {
        if (((remain >> i) & 1) == 1) break;
    }
    cout << bar_size << " " << bar - i;
}

