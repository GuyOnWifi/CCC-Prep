#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<pair<int, int>> roads[100001];
int dist[100001];
int danger[100001];

void bfs(int start, int target) {
    deque<int> dq;
    dq.push_back(start);

    while (!dq.empty()) {
        int n = dq.front();
        dq.pop_front();
        for (auto [x, d] : roads[n]) {
            if (danger[n] + d < danger[x]) {
                // we found less dangerous way
                danger[x] = danger[n] + d;
                dist[x] = dist[n] + 1;
                if (d == 1) {
                    dq.push_back(x);
                } else {
                    dq.push_front(x);
                }
            } else if (danger[n] + d == danger[x] && dist[n] + 1 < dist[x]) {
                // we maximized distance, now minimize distance
                dist[x] = dist[n] + 1;
                dq.push_back(x);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    while (M--) {
        int a, b, t;
        cin >> a >> b >> t;
        
        roads[a].push_back({b, t});
        roads[b].push_back({a, t});
    }

    for (int i = 2; i <= N; i++) {
        danger[i] = 1000000;
        dist[i] = 1000000;
    }

    bfs(1, N);
    if (danger[N] == 1000000) {
        cout << -1;
    } else {
        cout << danger[N] << " " << dist[N];
    }
}
