// COCI '21 Contest 6 #3 Naboj

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<int> graph[200001];
int in_degree[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        in_degree[a]++;
        graph[b].push_back(a);
    }

    deque<int> q;
    vector<int> order;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            q.push_back(i);
        }
    }

    while (!q.empty()) {
        int t = q.front();
        q.pop_front();
        order.push_back(t);   

        for (auto x : graph[t]) {
            in_degree[x]--;
            if (in_degree[x] == 0) {
                q.push_back(x);
            }
        }
    }

    if (order.size() != N) {
        cout << -1;
        return 0;
    }
    // k
    cout << order.size() << endl;

    cout << order[0] << " " << 0 << endl;

    for (int i = 1; i < order.size(); i++) {
        cout << order[i] << " " << 1 << endl;
    }
}