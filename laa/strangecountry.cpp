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
    for (int i = 1; i <= N; ++i) {
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

int activated[300001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, K;
    cin >> N >> M >> K;

    vector<tuple<int, int, int, int>> edge_list;
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edge_list.push_back({w, x, y, i});
    }

    sort(edge_list.begin(), edge_list.end());

    for (int i = 1; i <= K; i++) {
        initialize();

        for (auto [w, x, y, idx] : edge_list) {
            if (activated[idx]) continue;
            if (isSameSet(x, y)) continue;
            unionSet(x, y);
            activated[idx] = i;
        }
    }

    for (int i = 0; i < M; i++) {
        cout << (activated[i] ? activated[i] : -1) << endl;
    }

}
