#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int main() {
    cout << 100000 << " " << 109996 << endl;

    for (int i = 2; i < 100000; i++) {
        cout << 1 << " " << i << " " << 1 << endl;
    }

    int n = 1000000;
    for (int i = 2; i < 10000; i++) {
        cout << i << " " << 100000 << " " << n - i << endl;
    }
}
