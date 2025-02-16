#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N;
int nkat[21];

// sums, bitmask
vector<pair<int, int>> sums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nkat[i];
    }

    // bit masking approach?
    for (int i = 1; i < (1 << N); i++) {
        int s = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                s += nkat[j];
            }
        }
        sums.push_back({s, i});
    }

    sort(sums.begin(), sums.end());

    int ans = INT_MAX;
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < (1 << N) - 2; i++) {
        if (sums[i].second & sums[i + 1].second) continue;
        
        int diff = abs(sums[i].first - sums[i + 1].first);
        if (diff < ans) {
            s1 = sums[i].second;
            s2 = sums[i + 1].second;
            ans = diff;
        }
    }

    for (int i = 0; i < N; i++) {
        if (s1 & (1 << i)) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        if (s2 & (1 << i)) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}
