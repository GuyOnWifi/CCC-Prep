#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<pair<int, int>> graph[5001];
int pencils[5001];

int costs[5001];
void dijkstra(int start) {
    // cost, node
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [c, x] = pq.top();
        pq.pop();

        if (-c > costs[x]) continue;
        for (auto [n, w] : graph[x]) {
            if (costs[x] + w >= costs[n]) continue;
            costs[n] = costs[x] + w;
            pq.push({-costs[n], n});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;
    
    for (int i = 0; i < T; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        graph[x].push_back({y, c});
        graph[y].push_back({x, c});
    }

    int K;
    cin >> K;

    int z, p;
    for (int i = 0; i < K; i++) {
        cin >> z >> p;
        pencils[z] = p;
    }

    int D;
    cin >> D;

    for (int i = 0 ; i < 5001; i++) costs[i] = 100000;
    costs[D] = 0;
    dijkstra(D);

    int ans = INT_MAX;
    for (int i = 0; i < 5001; i++) {
        if (!pencils[i]) continue;
        ans = min(ans, pencils[i] + costs[i]);
    }

    cout << ans;
}
