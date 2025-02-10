// Canadian Computing Competition: 2023 Stage 1, Senior #3

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

char grid[2000][2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            grid[i][j] = 'b';
        }
    }

    int N, M, R, C;
    cin >> N >> M >> R >> C;

    if (R == 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M - 1; j++) {
                grid[i][j] = 'a';
            }
            grid[i][M - 1] = 'b';
        }

        for (int i = C; i < M; i++) {
            grid[N - 1][i] += 1;
        }
    } else if (C == 0) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N - 1; j++) {
                grid[j][i] = 'a';
            }
            grid[N - 1][i] = 'b';
        }

        for (int i = R; i < N; i++) {
            grid[i][M - 1] += 1;
        }
    } else if (R == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = 'a';
            }
        }

        int needed = M - C;
        if (M % 2 == 1 && needed % 2 == 1) {
            grid[0][M / 2] = 'b';
            needed--;
        }
        if (needed % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        for (int i = 0; i < needed / 2; i++) {
            grid[0][i] = 'b';
            grid[0][M - i - 1] = 'b';
        }
    } else if (C == M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = 'a';
            }
        }

        int needed = N - R;
        if (N % 2 == 1 && needed % 2 == 1) {
            grid[N / 2][0] = 'b';
            needed--;
        }
        if (needed % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        for (int i = 0; i < needed / 2; i++) {
            grid[i][0] = 'b';
            grid[N - i - 1][0] = 'b';
        }
    } else {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = 'a';
            }
        }
    
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < N; j++) {
                grid[j][i] = 'a';
            }
        }
    }


    // print it out
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
