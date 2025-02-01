#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<pair<int, int>> tree[500001];
vector<int> weights;

// node, distqance
pair<int, int> find_longest(int start, int prev, int sum) {

    int max_sum = sum;
    int max_node = start;
    for (const auto& [next, weight] : tree[start]) {
        if (next == prev) continue;
        auto [node, dist] = find_longest(next, start, sum + weight);
        if (dist > max_sum) {
            max_sum = dist;
            max_node = node;
        }
    }
    return {max_node, max_sum};
}

bool dfs(int start, int prev, int target) {
    if (start == target) return true;

    for (const auto& [next, weight] : tree[start]) {
        if (next == prev) continue;

        if (dfs(next, start, target)) {
            weights.pb(weight);
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].pb({v, w});
        tree[v].pb({u, w});
    }

    int node_start = find_longest(1, 0, 0).first;
    auto [node_end, dist] = find_longest(node_start, 0, 0);
    cout << dist << "\n";

    dfs(node_start, 0, node_end);
    int ans = INT_MAX;
    int t_d = 0;
    for (auto i : weights) {
        t_d += i;
        ans = min(ans, max(t_d, dist - t_d));
    }
    cout << ans << "\n";
}
