#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N;

// edges
vector<pair<int, int>> edges;

int p[100001], height[100001], setSize[100001];
int numSets;

void initialize() {
    for (int i = 0; i <= N; ++i) {
        p[i] = i;
        setSize[i] = 1; // Optional feature
    }
    numSets = N; // Optional feature
}

int findSet(int i) {
    if (p[i] == i)
        return i;
    p[i] = findSet(p[i]); // Path Compression
    return p[i];
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

int numDisjointSets() {
    return numSets;
}

int sizeOfSet(int i) {
    return setSize[findSet(i)];
}

void unionSet(int i, int j) {
    if (isSameSet(i, j))
        return;

    int x = findSet(i);
    int y = findSet(j);

    if (height[x] > height[y])
        swap(x, y);

    p[x] = y;

    if (height[x] == height[y])
        height[y]++; // Height Compression

    setSize[y] += setSize[x];
    numSets--;
}

// pen #, cost
vector<pair<int, int>> farm[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int e;
        cin >> e;

        vector<int> corners, costs;
        for (int j = 0; j < e; j++) {
            int c;
            cin >> c;
            corners.push_back(c);
        }

        for (int j = 0; j < e; j++) {
            int c;
            cin >> c;
            costs.push_back(c);
        }

        for (int j = 0; j < e; j++) {
            // first time encountering this fence
            int curr = corners[j];
            int next = corners[(j + 1) % e];
            
            farm[curr][next].push_back({i, costs[j]});
            farm[next][curr].push_back({i, costs[j]});
        }
    }

    // first pass (no outside)
    vector<tuple<int, int, int>> edge_list;

    for (int i = 0; i < 1001; i++) {
        for (int j = i; j < 1001; j++) {
            if (farm[i][j].size() == 2) {
                auto [p1, c1] = farm[i][j][0];
                auto [p2, c2] = farm[i][j][1];
                edge_list.push_back({c1, p1, p2});
            }
        }
    }
    
    int ans1 = 0;
    initialize();
    sort(edge_list.begin(), edge_list.end());
    for (auto [w, x, y] : edge_list) {
        if (isSameSet(x, y)) continue;
        unionSet(x, y);
        ans1 += w;
    }

    // second pass
    for (int i = 0; i < 1001; i++) {
        for (int j = i; j < 1001; j++) {
            if (farm[i][j].size() == 1) {
                auto [p1, c1] = farm[i][j][0];
                edge_list.push_back({c1, p1, 0});
            } 
        }
    }

    int ans2 = 0;
    initialize();
    sort(edge_list.begin(), edge_list.end());
    for (auto [w, x, y] : edge_list) {
        if (isSameSet(x, y)) continue;
        unionSet(x, y);
        ans2 += w;
    }

    cout << min(ans1, ans2);
}
