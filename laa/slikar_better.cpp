#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int R, C;
char grid[50][50];
int water[50][50];
bool visited[50][50];

// i, j, time
deque<tuple<int, int, int>> pos;
deque<tuple<int, int, int>> flood;

void bfs_water() {
    while (!flood.empty()) {
        auto [i, j, m] = flood.front();
        flood.pop_front();

        if (i < 0 || i >= R || j < 0 || j >= C) continue;


        if (grid[i][j] == 'X' || grid[i][j] == 'D') continue; 
        if (water[i][j] != -1) continue;

        water[i][j] = m;
        flood.push_back({i+1, j, m + 1});
        flood.push_back({i, j+1, m + 1});
        flood.push_back({i-1, j, m + 1});
        flood.push_back({i, j-1, m + 1});
        
    }
}

int bfs() {
    while (!pos.empty()) {
        auto [i, j, m] = pos.front();        
        pos.pop_front();

        if (i < 0 || i >= R || j < 0 || j >= C) continue;

        if (visited[i][j]) continue;
        visited[i][j] = true;
        
        if (grid[i][j] == '.' && m < water[i][j]) {
            pos.push_back({i+1, j, m + 1});
            pos.push_back({i, j+1, m + 1});
            pos.push_back({i-1, j, m + 1});
            pos.push_back({i, j-1, m + 1});
        } else if (grid[i][j] == 'D') {
            return m;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;

            cin >> c;
            if (c == 'S') {
                pos.push_back({i, j, 0});
                grid[i][j] = '.';
            } else if (c == '*') {
                flood.push_back({i, j, 0});
                grid[i][j] = '.';
            } else {
                grid[i][j] = c;
            }
        }
    }

    memset(water, -1, sizeof(water));
    bfs_water();

    int r = bfs();
    if (r == -1) {
        cout << "KAKTUS";
    } else {
        cout << r;
    }
}
