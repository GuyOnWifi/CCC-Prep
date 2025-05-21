#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

ll arr[3000];
ll dp[3000][3000][2];

ll recurse(int start, int end, bool taro_turn) {
  if (start > end)
    return 0;
  if (dp[start][end][taro_turn] != -1)
    return dp[start][end][taro_turn];

  if (taro_turn) {
    ll take_first = arr[start] + recurse(start + 1, end, false);
    ll take_second = arr[end] + recurse(start, end - 1, false);
    return dp[start][end][taro_turn] = max(take_first, take_second);
  } else {
    ll take_first = -arr[start] + recurse(start + 1, end, true);
    ll take_second = -arr[end] + recurse(start, end - 1, true);
    return dp[start][end][taro_turn] = min(take_first, take_second);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  memset(dp, -1, sizeof(dp));
  cout << recurse(0, N - 1, true);
}
