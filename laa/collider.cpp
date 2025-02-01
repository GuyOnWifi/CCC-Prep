#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int diameter, furthest;
vector<int> tree[400001];
vector<int> path;

void find_longest(int start, int prev, int dist) {
    if (diameter < dist) {
        diameter = dist;
        furthest = start;
    }
    for (int x : tree[start]) {
        if (x == prev) continue;
        find_longest(x, start, dist + 1);
    }
}

bool get_path(int start, int end, int prev) {
    if (start == end) {
        path.pb(start);
        return true;
    }

    for (auto x : tree[start]) {
        if (x == prev) continue;
        if (get_path(x, end, start)) {
            path.pb(start);
            return true;
        }
    }
    return false;
}

ll find_colliders(int start, int prev, int depth, int dist) {
    if (dist == depth) return 1;
    ll sum = 0;
    for (auto x : tree[start]) {
        if (x == prev) continue;
        sum += find_colliders(x, start, depth, dist + 1);
    }
    return sum;
}

ll one_center(int c1) {
    vector<ll> colls;
    for (auto x : tree[c1]) {
        ll a = find_colliders(x, c1, diameter / 2, 1);
        colls.pb(a);
    }

    ll total = 0;
    for (int i = 0; i < colls.size(); i++) {
        for (int j = i + 1; j < colls.size(); j++) {
            total += colls[i] * colls[j];
        }
    }
    return total;
}

ll two_center(int c1, int c2) {
    ll a1 = find_colliders(c1, -1, (diameter / 2) + 1, 0);
    ll a2 = find_colliders(c2, -1, (diameter / 2) + 1, 0);
    return a1 * a2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    find_longest(1, -1, 0);
    int start = furthest;
    diameter = 0;
    find_longest(start, -1, 0);
    int end = furthest;

    get_path(start, end, -1);
    
    ll num_ans = 0;
    // odd size (1 center)
    if (path.size() % 2 == 1) {
        int center = path[path.size() / 2];    
        num_ans = one_center(center);
    }

    // even path (2 centers)
    if (path.size() % 2 == 0) {
        int center1 = path[path.size() / 2];
        int center2 = path[path.size() / 2 - 1];
        num_ans = two_center(center1, center2);
    }

    cout << diameter + 1 <<  " " << num_ans << endl;
}