// CCC '24 S2 - Heavy-Light Composition

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    cin >> T >> N;

    while (T--) {
        string s;
        cin >> s;

        map<char, int> m;
        for (char& c : s) {
            m[c]++;
        }
        bool is_heavy;
        is_heavy = m[s[0]] > 1;
        for (int i = 1; i < s.length(); i++) {
            if ((m[s[i]] > 1) != !is_heavy) {
                cout << "F\n";
                break;
            }
            if (i == s.length() - 1) {
                cout << "T\n";
            }
            is_heavy = !is_heavy;
        }
    }

}
