#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> chores;

    int T, C;
    cin >> T >> C;

    while (C--) {
        int time;
        cin >> time;
        chores.pb(time);
    }

    sort(chores.begin(), chores.end());

    int sum = 0;
    int amnt = 0;
    while (sum <= T) {
        sum += chores[amnt];
        amnt += 1;
    }

    cout << amnt - 1 << endl;
}
