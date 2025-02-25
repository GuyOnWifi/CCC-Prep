// DWITE '06 R5 #5 - Prime Palindromes
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

bool is_composite[1000000];

void sieve() {
    for (int i = 2; i < 1000; i++) {
        if (is_composite[i] == false) {
            for (int j = i * i; j < 1000000; j += i) {
                is_composite[j] = true;
            }
        }
    }
}

bool is_pal(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    for (int i = 0; i < 5; i++) {
        int L, U;
        cin >> L >> U;
        
        int count = 0;
        for (; L <= U; L++) {
            if (is_pal(to_string(L)) && !is_composite[L]) count++;
        }
        cout << count << "\n";
    }
}
