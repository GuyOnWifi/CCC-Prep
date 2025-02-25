#include <bits/stdc++.h>
using namespace std;

vector<int> tree[10000];

int diameter, furthest;

void find_longest(int start, int prev, int dist) {
    if (diameter < dist) {
        diameter = dist;
        furthest = start;
    }
    for (int x : tree[start]) {
        if (x == prev) continue;
        find_longest(x, start, dist + 1);
    }
}