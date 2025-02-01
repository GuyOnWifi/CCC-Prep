#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<int> graph[1000];
int visited[1000];
vector<int> order;

void toposort(int x) {
    visited[x] = true;

    for (auto y : graph[x]) {
        if (visited[y]) continue;
        toposort(y);
    }
    order.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}
