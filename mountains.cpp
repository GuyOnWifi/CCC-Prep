// CCC '23 S2 - Symmetric Mountains

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<int> mountains;
int memo[5000][5000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        mountains.pb(h);
    }

    cout << 0 << " ";
    for (int l = 1; l < n; l++) {
        int shortest = INT_MAX;
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            memo[i][j] = memo[i + 1][j - 1] + abs(mountains[i] - mountains[j]);
            shortest = min(memo[i][j], shortest);
        }
        cout << shortest << " ";
    }
}
