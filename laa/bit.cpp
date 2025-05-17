#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

ll BIT[2][100001];

void update(int tree, int pos, ll val) {
  while (pos <= 100000) {
    BIT[tree][pos] += val;
    pos += pos & -pos;
  }
}

ll query(int tree, int pos) {
  ll sum = 0;
  while (pos > 0) {
    sum += BIT[tree][pos];
    pos -= pos & -pos;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    int num;
    cin >> num;
    update(0, i, num);
    update(1, num, 1);
  }

  for (int i = 0; i < M; i++) {
    char c;
    cin >> c;
    if (c == 'C') {
      int x, v;
      cin >> x >> v;
      ll val = query(0, x) - query(0, x - 1);
      update(0, x, -val);
      update(0, x, v);
      update(1, val, -1);
      update(1, v, 1);
    } else if (c == 'S') {
      int l, r;
      cin >> l >> r;
      cout << query(0, r) - query(0, l - 1) << "\n";
    } else {
      int v;
      cin >> v;
      cout << query(1, v) << "\n";
    }
  }
}
