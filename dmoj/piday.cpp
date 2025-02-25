#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<vector<int>> memo(251, vector<int> (251, -1));

int num_ways(int n, int k) {
    if (n < 0) return 0;
    if (k == 1) return 1;
    if (memo[n][k] != -1) return memo[n][k];

    int sum = 0;
    for (int i = 0;;i++) {
        int ways = num_ways(n - k * i, k - 1);
        sum += ways;
        if (ways == 0) break;
    }
    memo[n][k] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << num_ways(n - k, k);
}
