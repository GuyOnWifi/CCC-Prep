#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;
    
    map<pair<int, int>, bool> trees;

    while (T--) {
        int R, C;
        cin >> R >> C;

        trees[make_pair(R - 1, C - 1)] = true;
    }

    int largest = 1;
    bool is_largest = true;
    for (int size = 2; size <= N; size++) {
        for (int r = 0; r < N - size + 1; r++) {
            for (int c = 0; c < N - size + 1; c++) {

                is_largest = true;
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (trees[make_pair(r + i, c + j)]) is_largest = false;
                    }
                }

                if (is_largest) {
                    largest = max(largest, size);
                    break;
                }
            }
            if (is_largest) break;
        }
    }

    cout << largest;
}