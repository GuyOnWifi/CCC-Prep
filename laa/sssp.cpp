// Solve the Single Source Shortest Path problem.
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<pair<int, int>> graph[1001];
int tree[1001];
int N, M;

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, n] = pq.top();
        pq.pop();

        if (-d > tree[n]) continue;
        for (auto [x, w] : graph[n]) {
            if (tree[n] + w >= tree[x]) continue;
            tree[x] = tree[n] + w;
            pq.push({-tree[x], x});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 0; i <= N; i++) {
        tree[i] = 1000000;
    }
    tree[1] = 0;
    dijkstra();

    for (int i = 1; i <= N; i++) {
        if (tree[i] == 1000000) {
            cout << -1 << endl;
        } else {
            cout << tree[i] << endl;
        }
    }
}
