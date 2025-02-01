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
    cin >> N;

    string a, b;
    cin >> a;
    cin >> b;

    int occ = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == 'C' && b[i] == 'C') occ++;
    }

    cout << occ;
}
