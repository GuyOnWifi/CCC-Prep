// RGPC '17 P4 - Snow Day

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<pair<int, int>> graph[10001];
int in_degree[10001];
int dist[10001];
int points[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        in_degree[b]++;
    }

    deque<int> q;

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            q.push_back(i);
        }
    }

    vector<int> output;

    while (!q.empty()) {
        int t = q.front();
        q.pop_front();
        output.push_back(t);

        for (auto [x, d] : graph[t]) {
            in_degree[x]--;
            if (in_degree[x] == 0) {
                q.push_back(x);
            }
        }
    }

    if (output.size() != N) {
        cout << -1;
        return 0;
    }

    points[1] = 1;
    for (auto s : output) {
        for (auto [x, d] : graph[s]) {
            int new_dist = dist[s] + d;
            int new_scenic = points[s] + 1;

            if (new_dist == dist[x]) {
                if (new_scenic > points[x]) {
                    dist[x] = new_dist;
                    points[x] = new_scenic;
                }
            } else if (new_dist > dist[x]) {
                dist[x] = new_dist;
                points[x] = new_scenic;
            }
        }
    }

    cout << dist[N] << " " << points[N] << endl;

}
