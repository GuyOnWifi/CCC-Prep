#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string dir;

    while (true) {
        int inp;
        cin >> inp;

        if (inp == 99999) break;

        int steps = 0;
        
        steps += inp % 10;
        inp /= 10;

        steps += (inp % 10) * 10;
        inp /= 10;

        steps += (inp % 10) * 100;
        inp /= 10;

        int ins = 0;
        ins += inp % 10;
        inp /= 10;
        ins += inp % 10;
        inp /= 10;

        if (ins == 0) {
            // nothing
        }
        else if (ins % 2 == 1) {
            dir = "left";
        } else {
            dir = "right";
        }
        
        cout << dir << " " << steps << endl;
    }
}
