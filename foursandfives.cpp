#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    cin >> i;

    int num_fours = floor(i / 4);
    int surplus = i - num_fours * 4;

    if (surplus > num_fours) {
        cout << 0;
    } else {
        num_fours = num_fours - surplus;
        cout << 1 + floor(num_fours / 5);
    }
}
