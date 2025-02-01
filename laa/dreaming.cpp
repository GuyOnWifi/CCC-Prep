#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<pair<int, int>> forest[100001];
bool visited[100001];

int max_dist, furthest;

int temp_dist[100001];
int upper_dist[100001];
int lower_dist[100001];

vector<int> all_furthest;
vector<int> all_furthest_2;

int min_travel = INT_MAX;

void find_longest(int start, int prev, int dist[]) {
    visited[start] = true;

    for (auto [x, w] : forest[start]) {
        if (x == prev) continue;
        dist[x] = dist[start] + w;
        if (dist[x] > max_dist) {
            max_dist = dist[x];
            furthest = x;
        }
        find_longest(x, start, dist);
    }
}

void find_center(int start, int prev) {
    int travel = max(upper_dist[start], lower_dist[start]);
    if (travel < min_travel) {
        min_travel = travel;
    }
    for (auto [x, w] : forest[start]) {
        if (x == prev) continue;
        find_center(x, start);
    }
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    for (int i = 0; i < M; i++) {
        forest[A[i]].pb({B[i], T[i]});
        forest[B[i]].pb({A[i], T[i]});
    }
    
    // first pass: find the farthest node
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        max_dist = 0;
        furthest = i;
        find_longest(i, -1, temp_dist);
        all_furthest.pb(furthest);
    }

    memset(visited, false, sizeof(visited));
    // second pass: find the weights above
    for (int x : all_furthest) {
        max_dist = 0;
        furthest = x;
        find_longest(x, -1, upper_dist);
        all_furthest_2.pb(furthest);
    }

    memset(visited, false, sizeof(visited));
    // third pass: find the weights below
    for (int x : all_furthest_2) {
        max_dist = 0;
        find_longest(x, -1, lower_dist);
    }

    vector<int> all_max_travel;
    for (int x : all_furthest) {
        min_travel = INT_MAX;
        find_center(x, -1);
        cout << min_travel << endl;
        all_max_travel.pb(min_travel);
    }

    sort(all_max_travel.begin(), all_max_travel.end(), greater<int>());

    return all_max_travel[0] + all_max_travel[1] + L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l;
    cin >> n >> m >> l;

    int a[m];
    int b[m];
    int t[m];

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> t[i];
    }

    cout << travelTime(n, m, l, a, b, t) << endl;
}
