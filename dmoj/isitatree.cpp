#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int adj[4][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> adj[i][j];
        }
    }

    set<int> trees;
    int knots = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            if (adj[i][j]) {
                trees.insert(i);
                trees.insert(j);
                knots++;
            }
        }
    }

    cout << (trees.size() == knots + 1 ? "Yes" : "No");

}
