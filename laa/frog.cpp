// Educational DP Contest AtCoder A - Frog 1

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int heights[100001];
int N;
int memo[100001];

int jump(int start, int cost) {
    if (start >= N) return INT_MAX;
    if (start == N - 1) {
        return cost;
    }

    if (memo[start] != -1) return cost + memo[start];

    int j1 = jump(start + 1, cost + abs(heights[start] - heights[start + 1]));
    int j2 = jump(start + 2, cost + abs(heights[start] - heights[start + 2]));
    memo[start] = min(j1, j2) - cost;
    return memo[start] + cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << jump(0, 0);
}
