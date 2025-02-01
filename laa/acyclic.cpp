#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int graph[1001][1001];
int N;

bool visited[1001];
void dfs(int x) {
    if (visited[x]) {
        cout << "NO";
        exit(0);
    }
    visited[x] = true;

    for (int i = 0; i < N; i++) {
        if (graph[x][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int start;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int c; 
            cin >> c;
            graph[i][j] = c;
            if (c == 1) {
                start = i;
            }
        }
    }

    dfs(start);
    cout << "YES";
}
