#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    double *lengths = new double[n];

    int s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        lengths[i] = (s + j) / 2.0;
        s = j;
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        sum += w * lengths[i];
    }
    printf("%.6f", sum);
}
