#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

map<int, vector<pair<int,int>>> values;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;

            values[num].pb(make_pair(i, j));            
        }
    }

    while (Q--) {
        int k, r1, c1, r2, c2;
        cin >> k >> r1 >> c1 >> r2 >> c2;

        bool contains = false;
        for (auto list : values[k]) {
            int r = list.first;
            int c = list.second;
            if (r >= r1 - 1 && r < r2 && c >= c1 - 1&& c < c2) {
                contains = true;
            }
        }
        cout << (contains ? "yes" : "no") << endl;
    }
}
