#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> trees;
    while (T--) {
        int R, C;
        cin >> R >> C;

        trees.pb(make_pair(R + 1, C + 1));
    }

    sort(trees.begin(), trees.end());

    for (int i = 0; i < trees.size(); i++) {
        for (int j = 1; j < trees.size(); j++) {
            int height = trees[j].first - trees[i].first - 1;
            
        }
    }
}
