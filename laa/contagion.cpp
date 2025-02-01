#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

pair<int, int> coords[3001];

int N;

vector<ll> dist(3001, 1000000000000000);
void dijkstra(int start) {
    // dist, next
    priority_queue<pair<ll, int>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, n] = pq.top();
        pq.pop();

        if (-d > dist[n]) continue;

        for (int x = 1; x <= N; x++) {
            if (x == n) continue;
            ll dx = coords[x].first - coords[n].first;
            ll dy = coords[x].second - coords[n].second;
            ll spread = dx * dx + dy * dy;
            if (dist[n] + spread >= dist[x]) continue;

            dist[x] = dist[n] + spread;
            pq.push({-dist[x], x});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }

    int X;
    cin >> X;

    dist[X] = 0;
    dijkstra(X);

    sort(dist.begin() + 1, dist.begin() + N + 1);

    int Q;
    cin >> Q;

    while (Q--) {
        ll query;
        cin >> query;
        cout << upper_bound(dist.begin(), dist.begin() + N + 1, query) - dist.begin() - 1 << endl;
    }
}