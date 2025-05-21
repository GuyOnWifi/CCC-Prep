// CCO '22 P1 - Alternating Heights
#include <bits/stdc++.h>
#include <deque>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int ppl[3001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K, Q;
  cin >> N >> K >> Q;

  for (int i = 1; i <= N; i++) {
    cin >> ppl[i];
  }

  while (Q--) {
    int x, y;
    cin >> x >> y;
    vector<int> graph[3001];
    int in_degree[3001];
    memset(in_degree, 0, sizeof(in_degree));

    for (int i = x; i <= y; i += 2) {
      if (i + 1 <= y) {
        graph[ppl[i]].push_back(ppl[i + 1]);
      }
      if (i > x) {
        graph[ppl[i]].push_back(ppl[i - 1]);
      }
    }
    for (int i = 1; i <= K; i++) {
      for (int j : graph[i]) {
        in_degree[j]++;
      }
    }
    deque<int> q;
    for (int i = 1; i <= K; i++) {
      if (in_degree[i] == 0)
        q.push_back(i);
    }

    vector<int> res;
    while (!q.empty()) {
      int val = q.front();
      q.pop_front();
      res.push_back(val);

      for (auto x : graph[val]) {
        in_degree[x]--;
        if (in_degree[x] == 0) {
          q.push_back(x);
        }
      }
    }

    cout << res.size() << endl;
    if (res.size() == K) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
