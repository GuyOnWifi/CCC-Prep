#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<int> directedList[300001];
int visited_max[300001];

int V, E;

int find_max(int start) {
    if (visited_max[start]) return visited_max[start];
    visited_max[start] = start;

    // loop thru all subnodes
    for (int n : directedList[start]) {
        int res = find_max(n);
        visited_max[start] = max(visited_max[start], res);
    }

    return visited_max[start];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        directedList[a].pb(b);
    }

    // loop throuh all possible values of x 
    for (int x = V; x > 0; x--) {

        // find the maximum value in the chain
        int y = find_max(x);

        if (x < y) {
            cout << x << " " << y << endl;
            return 0;
        }
    }
    cout << -1;
}
