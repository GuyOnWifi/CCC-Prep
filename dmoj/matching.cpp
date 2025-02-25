#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    string S, T;

    cin >> N >> M >> S >> T;

    int len = lcm(S.length(), T.length());

    int count = 0;
    for (int i = 0; i < len; i++) {
        if (S[i % S.length()] == T[i % T.length()]) count++;
    }

    cout << N * S.length() / len * count;
}
