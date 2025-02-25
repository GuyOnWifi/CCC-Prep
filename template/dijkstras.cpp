#include <bits/stdc++.h>
using namespace std;

// vertex, weight
vector<pair<int, int>> graph[10000];
int dist[10000];

int main() {

    int start;

    // dist, node
    priority_queue<pair<int, int>> pq;

    // use large value
    for (int i = 0; i < 10000; i++) {
        dist[i] = 1000000;
    }
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, n] = pq.top();
        pq.pop();

        if (-d >= dist[n]) continue;
        
        for (auto [x, w] : graph[n]) {
            if (-d + w >= dist[x]) continue;
            dist[x] = -d + w;
            pq.push({dist[x], x});
        }
    }
}