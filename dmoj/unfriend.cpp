#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int *ways = new int[7];
    fill_n(ways, sizeof(ways), 1);

    for (int i = 1; i < n; i++) {
        int inv;
        cin >> inv;
        ways[inv] = ways[inv] * (1 + ways[i]);
    }
    cout << ways[n];
}
