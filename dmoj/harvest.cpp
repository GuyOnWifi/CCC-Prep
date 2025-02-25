#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

ll farm[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, K;
    cin >> N >> M >> K;

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;

        farm[a] += 1;
        farm[b + 1] -= 1; 
    }

    for (ll i = 0; i < 2; i++) {
        for (ll j = 1; j <= N; j++) {
            farm[j] = farm[j] + farm[j - 1];
        }
    }

    ll i = 1;
    ll j = 1;
    ll smallest = INT64_MAX;
    while (j <= N) {
        ll removed = farm[j] - farm[i - 1];
        ll width = j - i + 1;
        ll sum = M * width - removed;

        if (sum >= K) {
            smallest = min(smallest, width);
            i++;
        } else {
            j++;
        }
    }

    if (smallest == INT64_MAX) {
        cout << -1;
    } else {
        cout << smallest;
    }
}
