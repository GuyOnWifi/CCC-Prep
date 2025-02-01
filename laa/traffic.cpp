#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int P[1000000], S[1000000], D[1000000];
vector<int> adjList[1000000];

int total = 0;
int ans_city;
int ans_traffic = INT_MAX;

int dfs(int vertex, int prev) {
    int total_traffic = P[vertex];
    int busiest_edge = 0;
    for (int u : adjList[vertex]) {
        if (u != prev) {
            int local_traffic = dfs(u, vertex);
            busiest_edge = max(busiest_edge, local_traffic);
            total_traffic += local_traffic;
        }
    }
    busiest_edge = max(busiest_edge, total - total_traffic);

    if (busiest_edge < ans_traffic) {
        ans_traffic = busiest_edge;
        ans_city = vertex;
    }

    return total_traffic;
}

int LocateCentre(int N, int p[], int s[], int d[]) {
    
    for (int i = 0; i < N; i++) {
        P[i] = p[i];
        total += p[i];
    }

    for (int i = 0; i < N - 1; i++) {
        adjList[s[i]].pb(d[i]);
        adjList[d[i]].pb(s[i]);
    }

    dfs(0, -1);
    return ans_city;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> S[i];
        cin >> D[i];
    }    

    cout << LocateCentre(N, P, S, D) << endl;
}


