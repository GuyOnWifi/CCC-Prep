// DMPG '15 S2 - MMORPG

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<tuple<int, int, int, int>> regions;
bool visited[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, N;
    cin >> R >> N;

    for (int i = 0; i < R; i++) {
        int x, y, w, l;
        cin >> x >> y >> w >> l;
        regions.push_back({x, y, w, l});
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int px, py;
        cin >> px >> py;
        
        for (int j = 0; j < R; j++) {
            auto [rx, ry, w, l] = regions[j];

            if (visited[j]) continue;
            if (px >= rx && px < rx + w && py >= ry && py < ry + l) {
                visited[j] = true;
                ans++;
            }
        }
    }

    cout << ans << endl;
}
