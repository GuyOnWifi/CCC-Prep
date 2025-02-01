#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<int> directedList[300001];
int visited_max[300001];

int V, E;

void find_max(int start, int node) {
    for (auto n : directedList[node]) {
        if (visited_max[n]) continue;
        if (start > n) {
            visited_max[n] = start;
            find_max(start, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        // reverse graph
        directedList[b].pb(a);
    }

    // loop throuh all possible values of y
    for (int y = V; y > 0; y--) {
        find_max(y, y);
    }

    // loop throuh all possible values of x
    for (int x = V; x > 0; x--) {
        if (visited_max[x]) {
            cout << x << " " << visited_max[x] << endl;
            return 0;
        }
    }

    cout << -1;
}
