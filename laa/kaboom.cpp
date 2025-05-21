// COCI '09 Contest 4 #5 Kaboom
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int dp[1001][1001][2];
int N, A, B;

int recurse(int ds, int ss, bool fold_left) {
  if (dp[ds][ss][fold_left] != -1)
    return dp[double_sided][single_sided][fold_left];
  dp[double_sided][single_sided][fold_left] = 1;
  if (!fold_left) {
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));
}
