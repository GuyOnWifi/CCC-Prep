#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

set<int> tree[100000];
set<int> pho;
int edges = 0;

pair<int, int> find_longest(int start, int prev, int sum) {

    int max_sum = sum;
    int max_node = start;
    for (auto next : tree[start]) {
        if (next == prev) continue;
        auto [node, dist] = find_longest(next, start, sum + 1);
        if (dist > max_sum) {
            max_sum = dist;
            max_node = node;
        }
    }
    return {max_node, max_sum};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int p;
    for (int i = 0; i < M; i++) {
        cin >> p;
        pho.insert(p);
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].insert(b);
        tree[b].insert(a);
        edges += 2;
    }

    bool prune = true;
    // prune leaves
    while(prune) {
        prune = false;
        for (int i = 0; i < N; i++) {
            if (tree[i].size() == 1 && !pho.count(i)) {
                prune = true;
                int leaf = *tree[i].begin();
                tree[leaf].erase(i);
                tree[i].erase(leaf);
                edges -= 2;
            }
        }
    }

    int node_start = find_longest(p, -1, 0).first;
    auto [node_end, dist] = find_longest(node_start, -1, 0);
    cout << edges - dist << "\n";

}