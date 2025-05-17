// DWITE '11 R5 #4 - Cube World
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int world[22][22];
bool visited[22][22];

bool dfs(int i, int j, int h) {
  if (world[i][j] == -1)
    return false;
  if (visited[i][j])
    return true;
  visited[i][j] = true;

  if (world[i][j + 1] < h && !dfs(i, j + 1, h))
    return false;
  if (world[i][j - 1] < h && !dfs(i, j - 1, h))
    return false;
  if (world[i + 1][j] < h && !dfs(i + 1, j, h))
    return false;
  if (world[i - 1][j] < h && !dfs(i - 1, j, h))
    return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int a = 0; a < 5; a++) {
    memset(world, -1, sizeof(world));

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        cin >> world[i][j];
      }
    }

    int ans = 0;

    for (int i = 2; i < N; i++) {
      for (int j = 2; j < M; j++) {
        int h = 1;
        while (true) {
          memset(visited, 0, sizeof(visited));
          if (dfs(i, j, world[i][j] + h)) {
            h++;
            ans++;
          } else {
            break;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
