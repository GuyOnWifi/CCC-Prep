#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

ll cake[5001][5001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cake, 0, sizeof(cake));

    int N, M, K;
    cin >> N >> M >> K;

    while (K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cake[y1][x1] += 1;
        cake[y2 + 1][x2 + 1] += 1;

        cake[y1][x2 + 1] -= 1;
        cake[y2 + 1][x1] -= 1;
    }

    // PSA SUM
    for (int col = 0; col <= N; col++) {
        for (int row = 1; row <= M; row++) {
            cake[row][col] += cake[row - 1][col];
        }
    }

    for (int row = 0; row <= M; row++) {
        for (int col = 1; col <= N; col++) {
            cake[row][col] += cake[row][col - 1];
        }
    }

    // AGAIN
    for (int col = 0; col <= N; col++) {
        for (int row = 1; row <= M; row++) {
            cake[row][col] += cake[row - 1][col];
        }
    }

    for (int row = 0; row <= M; row++) {
        for (int col = 1; col <= N; col++) {
            cake[row][col] += cake[row][col - 1];
        }
    }



    int Q;
    cin >> Q;
    
    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << cake[y2][x2] - cake[y2][x1 - 1] - cake[y1 - 1][x2] + cake[y1 - 1][x1 - 1] << "\n";
    }
}
