#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> l;
    for (int i = 0; i < N; i++) {
        int t, d;
        cin >> t >> d;

        l.push_back({t, d});
    }

    sort(l.begin(), l.end());

    auto [prev_time, prev_d] = l[0];
    double max_speed = 0;
    for (int i = 1; i < l.size(); i++) {
        auto [t, d] = l[i];
        double sp = (double) abs(d - prev_d) / (t - prev_time);
        max_speed = max(max_speed, sp);
        prev_time = t;
        prev_d = d;
    }

    cout << max_speed;
}