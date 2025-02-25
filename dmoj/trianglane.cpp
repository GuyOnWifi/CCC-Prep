#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    cin >> C;

    int road[2][C];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < C; j++) {
            cin >> road[i][j];
        }
    }


    int len = 0;
    for (int i = 0; i < C; i++) {
        if (road[0][i] == 0) continue;
        len += 3;
        if (i == 0) continue;
        if (road[0][i-1] == 1) len -= 2;
    }
    for (int i = 0; i < C; i++) {
        if (road[1][i] == 0) continue;
        len += 3;
        if (road[0][i] == 1 && i % 2 == 0) len -= 2;
        if (i == 0) continue;
        if (road[1][i-1] == 1) len -= 2;
    }
    cout << len;
}
