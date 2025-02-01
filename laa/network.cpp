#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int f[100001];
int N;

// edges
vector<tuple<int, int, int>> edges;

int p[100001], height[100001], setSize[100001];
int numSets;

void initialize() {
    for (int i = 0; i < N; ++i) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> f[i];
    }

    initialize();
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
    }
    
    // compute diff array
    for (int i = 2; i <= N; i++) {
        edges.push_back({f[i] - f[i - 1], i, i - 1});
    }
    sort(edges.begin(), edges.end());

    int cost = 0;
    for (auto [w, a, b] : edges) {
        if (numDisjointSets() == 1) break;
        if (isSameSet(a, b)) continue;
        unionSet(a, b);
        cost += w;
    }

    cout << cost << endl;
}
