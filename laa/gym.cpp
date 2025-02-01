#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<int> town[100001];
bool gyms[100001];

int dragonite_town;
int edges;

int diameter, furthest;

void find_longest(int start, int prev, int dist) {
    if (diameter < dist) {
        diameter = dist;
        furthest = start;
    }
    for (int x : town[start]) {
        if (x == prev) continue;
        if (gyms[x]) find_longest(x, start, dist + 1);
    }
}

bool dfsPrune(int v, int p) {
    for (int x : town[v]) {
        if (x == p) continue;
        if (dfsPrune(x, v)) {
            gyms[v] = true;
        }
    }
    if (!gyms[v]) {
        edges -= 1;
    } 
    return gyms[v];
}

int max_single_connected_dist = 0;
void max_single_connection(int start, int prev, int dist) {
    max_single_connected_dist = max(max_single_connected_dist, dist);

    for (int x : town[start]) {
        if (x == prev) continue;
        if (!gyms[x]) continue;
        if (town[start].size() == 2) {
            max_single_connection(x, start, dist + 1);
        } else {
            max_single_connection(x, start, 0);
        }
    }

}

vector<int> path;
bool get_path(int start, int end, int prev) {
    if (start == end) {
        path.pb(start);
        return true;
    }

    for (auto x : town[start]) {
        if (x == prev) continue;
        if (get_path(x, end, start)) {
            path.pb(start);
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K >> dragonite_town;
    
    int g;
    for (int i = 0; i < K; i++) {
        cin >> g;
        gyms[g] = true;
    }
    gyms[1] = true;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        town[a].pb(b);
        town[b].pb(a);
        edges += 1;
    }


    dfsPrune(1, -1);
    find_longest(1, -1, 0);

    get_path(1, dragonite_town, 0);

    int drag_gym = -1;
    for (auto x : path) {
        if (gyms[x]) drag_gym++;
    }
    int dist_with_drag = (edges - drag_gym) + (path.size() - 1);
    int dist_without_drag = (edges * 2) - diameter;
    cout << min(dist_with_drag, dist_without_drag) << "\n";
}
