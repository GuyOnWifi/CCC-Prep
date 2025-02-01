#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int N, K;
vector<pair<int, int>> tree[200001];
vector<int> pandas;

int visited[200001];

void dfs(int start, int range_start, int range_end) {

    if (range_start > range_end) return;

    auto lower = lower_bound(pandas.begin(), pandas.end(), range_start);
    auto upper = upper_bound(pandas.begin(), pandas.end(), range_end);
    
    visited[start] = upper - lower;

    if (tree[start].empty()) return;
    sort(tree[start].begin(), tree[start].end());

    if (tree[start].size() == 1) {
        dfs(tree[start][0].second, range_start, range_end);
        return;
    }

    int prev_end = range_start - 1;
    for (int i = 0; i < tree[start].size() - 1; i++) {
        auto hill = tree[start][i];
        auto next_hill = tree[start][i + 1];
        int end = hill.first + (next_hill.first - hill.first) / 2;
        dfs(hill.second, max(range_start, prev_end + 1), min(range_end, end));
        prev_end = end;
    }

    auto last_hill = tree[start][tree[start].size() - 1];
    dfs(last_hill.second, max(range_start, prev_end + 1), range_end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].pb(make_pair(d, b));
    }

    for (int i = 0; i < K; i++) {
        int s;
        cin >> s;
        pandas.pb(s);
    }
    sort(pandas.begin(), pandas.end());

    dfs(1, *pandas.begin(), *pandas.rbegin());

    // print output
    cout << visited[1];
    for (int i = 2; i <= N; i++) {
        cout << " " << visited[i];
    }
    cout << endl;
}