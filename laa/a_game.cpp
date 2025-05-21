#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

ll arr[100];
pair<ll, ll> dp[100][100][2];

pair<ll, ll> recurse(int start, int end, bool first_turn) {
  if (start > end)
    return {0, 0};
  if (dp[start][end][first_turn].first || dp[start][end][first_turn].second)
    return dp[start][end][first_turn];

  if (first_turn) {
    pair<ll, ll> take_first = recurse(start + 1, end, false);
    take_first.first += arr[start];

    pair<ll, ll> take_last = recurse(start, end - 1, false);
    take_last.first += arr[end];

    return dp[start][end][first_turn] = max(take_first, take_last);
  } else {
    pair<ll, ll> take_first = recurse(start + 1, end, true);
    take_first.second += arr[start];

    pair<ll, ll> take_last = recurse(start, end - 1, true);
    take_last.second += arr[end];

    return dp[start][end][first_turn] =
               (take_first.second > take_last.second) ? take_first : take_last;
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

  pair<ll, ll> ans = recurse(0, N - 1, true);
  cout << ans.first << " " << ans.second << endl;
}
