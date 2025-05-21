// Educational DP Contest AtCoder N - Slimes
#include <bits/stdc++.h>
#include <climits>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

ll psa[401];
ll dp[401][401];
int arr[401];
ll recurse(int l, int r) {
  if (l >= r)
    return 0;
  if (dp[l][r])
    return dp[l][r];

  ll ans = LLONG_MAX;
  for (int i = l; i < r; i++) {
    ll cost = recurse(l, i) + recurse(i + 1, r) + psa[r] - psa[l - 1];
    ans = min(ans, cost);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  ll sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += arr[i];
    psa[i] = sum;
  }

  cout << recurse(1, N) << endl;
}
