#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    cin >> s;
    if (s == 0) {
        cout << 0;
        return 0;
    }
    
    int count = 0;

    count += 31 * (s / 720);
    s = s % 720;

    for (int h = 0;;h++) {
        if (h * 60 > s) break;

        int hour = (h + 11) % 12 + 1;

        if (hour == 10) continue;
        if (hour == 11 || hour == 12) {
            count++;
            continue;
        }

        for (int m = 1; m <= 5; m++) {
            if (m - hour + m <= 9 && m - hour + m >= 0) {
                if (h * 60 + m * 10 + m - hour + m > s) break;
                count++;
            }
            else continue;
        }
    }
    cout << count;
}
