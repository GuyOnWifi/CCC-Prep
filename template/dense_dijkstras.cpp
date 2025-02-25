#include <bits/stdc++.h>
using namespace std;

// vertex, weight
vector<pair<int, int>> graph[10000];
bool visited[10000];
int dist[10000];

int main() {

    int start, V;

    // use large value
    for (int i = 0; i < 10000; i++) {
        dist[i] = 1000000;
    }
    dist[start] = 0;

    for (int i = 0; i < V; i++) {
        int node = -1;
        for (int j = 0; j < V; j++) {
            if (!visited[j] && (node == -1 || dist[j] < dist[node])) {
                node = j;
            }
        }
        visited[node] = true;
        for (auto [x, w] : graph[node]) {
            dist[x] = min(dist[x], dist[node] + w);
        }
    }
}