#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<int> tree[500001];

int temp_dist[500001];
int dist_above[500001];
int dist_below[500001];

int max_dist;
int furthest;

void find_longest(int start, int prev, int dist[]) {
    for (int x : tree[start]) {
        if (x == prev) continue;
        dist[x] = dist[start] + 1;
        if (dist[x] > max_dist) {
            max_dist = dist[x];
            furthest = x;
        }
        find_longest(x, start, dist);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    find_longest(1, -1, temp_dist);
    max_dist = 0;
    find_longest(furthest, -1, dist_above);
    max_dist = 0;
    find_longest(furthest, -1, dist_below);

    for (int i = 1; i <= N; i++) {
        cout << max(dist_above[i], dist_below[i]) + 1 << "\n";
    }

}
