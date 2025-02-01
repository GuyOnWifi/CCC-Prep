#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string num;
    cin >> num;

    string output = "";
    int found = 0;
    for (int i = 0; i < n - k; i++) {
        int idx = found;
        for (int j = 0; j < (n-found) - (n-k) + i + 1; j++) {
            if (num[found + j] == '9') {
                idx = found + j;
                break; 
            }
            if (num[found + j] > num[idx]) {
                idx = found + j;
            }
        }
        output += num[idx];
        found = idx + 1;
    }
    cout << output;
}

