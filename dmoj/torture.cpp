// DWITE '06 R5 #5 - Prime Palindromes
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

bool is_composite[100000];
bool segment[20000000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll L, U;
    cin >> L >> U;
    
    // sieve 


    for (int i = 2; i < 100000; i++) {
        if (is_composite[i] == false) {
            for (int64_t j = 2 * i; j < 100000; j += i) {
                is_composite[j] = true;
            }
            ll start;
            if (L % i == 0) {
                start = L;
            }
            else { 
                start = ((L / i) + 1) * i; 
            }

            if (start == i) start += i;

            for (ll j = start; j < U; j += i) {
                segment[j - L] = true;
            }
        }
    }
    int count = 0;
    for (ll i = L; i < U; i++) {
        if (i == 1) continue;
        if (!segment[i - L]) count++;
    }
    cout << count << "\n";
    
}
