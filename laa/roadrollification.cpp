// DMOPC '20 Contest 2 P3 - Roadrollification

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int population[200001];

vector<int> graph[200001];
int in_degree[200001];

vector<int> reversed_graph[200001];
int reversed_in_degree[200001];

ll in_ppl[200001];
ll out_ppl[200001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        population[i] = p;
        in_ppl[i] = p;
        out_ppl[i] = p;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        in_degree[v]++;

        reversed_graph[v].push_back(u);
        reversed_in_degree[u]++;
    }

    // forwards
    deque<int> q;
    vector<int> output;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) q.push_back(i);
    }

    while (!q.empty()) {
        int t = q.front();
        q.pop_front();
        output.push_back(t);

        for (auto x : graph[t]) {
            in_degree[x]--;
            if (in_degree[x] == 0) q.push_back(x);
        }
    }

    // get ppl in
    for (int i = 0; i < output.size(); i++) {
        int n = output[i];

        for (auto x : graph[n]) {
            in_ppl[x] += in_ppl[n];
        }
    }
    
    // backward
    q.clear();
    output.clear();
    for (int i = 1; i <= N; i++) {
        if (reversed_in_degree[i] == 0) q.push_back(i);
    }

    while (!q.empty()) {
        int t = q.front();
        q.pop_front();
        output.push_back(t);

        for (auto x : reversed_graph[t]) {
            reversed_in_degree[x]--;
            if (reversed_in_degree[x] == 0) q.push_back(x);
        }
    }

    // get ppl out
    for (int i = 0; i < output.size(); i++) {
        int n = output[i];

        for (auto x : reversed_graph[n]) {
            out_ppl[x] += out_ppl[n];
        }
    }

    ll connections = 0;
    ll max_bi = INT_MIN;

    for (int i = 1; i <= N; i++) {
        connections += (ll)(population[i]) * (out_ppl[i] - 1);

        for (auto x : graph[i]) {
            ll new_connections = (in_ppl[x] - in_ppl[i]) * (out_ppl[i] - out_ppl[x]);
            max_bi = max(max_bi, new_connections);
        }
    }


    cout << connections + max_bi;
}
