// Educational DP Contest AtCoder D - Knapsack 1

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int N, W;
ll weights[101];
ll values[101];
ll memo[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;
    
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = W; j >= 0; j--) {
            ll with = 0;
            if (j >= weights[i]) {
                with = memo[j - weights[i]] + values[i];
            }
            ll without = memo[j];
            memo[j] = max(with, without);
        }
    }
    cout << memo[W] << endl;
}
