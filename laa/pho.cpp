#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<int> tree[100000];
bool pho[100000];
int edges = 0;
int diameter, furthest;

void find_longest(int start, int prev, int dist) {
    if (diameter < dist) {
        diameter = dist;
        furthest = start;
    }
    for (int x : tree[start]) {
        if (x == prev) continue;
        if (pho[x]) find_longest(x, start, dist + 1);
    }
}

bool dfsPrune(int v, int p) {
    for (int x : tree[v]) {
        if (x == p) continue;
        if (dfsPrune(x, v)) {
            pho[v] = true;
        }
    }
    if (!pho[v]) {
        edges -= 1;
    } 
    return pho[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    int p;
    for (int i = 0; i < M; i++) {
        cin >> p;
        pho[p] = true;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
        edges += 1;
    }

    dfsPrune(p, -1);
    find_longest(p, -1, 0);
    find_longest(furthest, -1, 0);
    
    cout << edges * 2 - diameter << "\n";

}
