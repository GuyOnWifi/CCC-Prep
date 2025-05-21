#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

ll BIT[200001];
void update(int pos, ll val) {
  while (pos <= 200001) {
    BIT[pos] += val;
    pos += pos & -pos;
  }
}

ll query(int pos) {
  ll sum = 0;
  while (pos > 0) {
    sum += BIT[pos];
    pos -= pos & -pos;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  cin >> N >> Q;

  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    update(i, a);
  }

  while (Q--) {
    char c;
    cin >> c;

    if (c == 'S') {
      int l, r;
      cin >> l >> r;
      cout << query(r) - query(l - 1) << "\n";
    } else if (c == 'U') {
      int i, x;
      cin >> i >> x;
      ll val = query(i) - query(i - 1);
      update(i, -val);
      update(i, x);
    }
  }
}
