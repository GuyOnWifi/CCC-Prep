#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

set<int> visited;
set<set<int>> all_visited;
bool adjMatrix[1000][1000];
int N;

void dfs(int start) {
    if (visited.count(start)) return;
    visited.insert(start);
    for (int i = 0; i < N; i++) {
        if (adjMatrix[start][i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        visited.clear();
        dfs(i);
        all_visited.insert(visited);
    }

    for (auto v : all_visited) {
        for (auto n : v) {
            cout << n + 1 << " ";
        }
        cout << endl;
    }
}
