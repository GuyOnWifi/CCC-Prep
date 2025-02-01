#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<pair<int, double>> roads[1001];
double dist[1001];
int intersections[1001];

void dijkstra() {
    // time, intersections, node
    priority_queue<tuple<double, int, int>> pq;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        auto [t, i, n] = pq.top();
        pq.pop();


        if (-t > dist[n]) continue;
        if (-i > intersections[n]) continue;

        for (auto [x, w] : roads[n]) {
            if (dist[n] + w > dist[x]) continue;
            if (fabs(dist[n] + w - dist[x]) < 0.00001 && intersections[n] + 1 > intersections[x]) continue;

            dist[x] = dist[n] + w;
            intersections[x] = intersections[n] + 1;
            pq.push({-dist[x], -intersections[x], x});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int m, n;
        double d, s;
        cin >> m >> n >> d >> s;
        roads[m].push_back({n , d / s});
        roads[n].push_back({m , d / s});
    }

    for (int i = 0; i < 1001; i++) {
        dist[i] = 100000;
        intersections[i] = 100000;
    }

    dist[1] = 0;
    intersections[1] = 0;
    
    dijkstra();
    cout << intersections[V] << "\n";
    cout << round(dist[V] * 20) << "\n";
}
