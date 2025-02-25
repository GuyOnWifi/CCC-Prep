// DMPG '17 S2 - Anime Conventions

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N;
int parents[100001];

void init() {
    for (int i = 1; i <= N; i++) {
        parents[i] = i;
    }
}

int find_set(int v) {
    if (v == parents[v]) return v;
    return parents[v] = find_set(parents[v]);   // path compression
}

bool union_set(int x, int y) {
    int a = find_set(x);
    int b = find_set(y);
    if (a == b) return false;
    parents[a] = b;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; 
    cin >> N >> Q;
    
    init();
    for (int i = 0; i < Q; i++) {
        char q;
        int x, y;
        cin >> q >> x >> y;

        if (q == 'A') {
            union_set(x, y);
        } else if (q == 'Q') {
            cout << (find_set(x) == find_set(y) ? 'Y' : 'N') << endl;
        }
    }
}
