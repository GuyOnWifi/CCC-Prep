#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    map<char, int> occ;

    for (auto const& c : s1) {
        occ[c]++;
    }

    for (auto const& c : s2) {
        occ[c]--;
    }
    

    int wildcards = abs(occ['*']);
    int is_anagram = true;
    for (auto const& x : occ) {
        if (x.first == '*') continue;
        if (x.second == 0) continue;
        wildcards -= abs(x.second);
    }

    if (wildcards < 0) {
        cout << "N";
    } else {
        cout << "A";
    }
}
