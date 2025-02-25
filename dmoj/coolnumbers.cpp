#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int i = (int) ceil(pow(a, 1.0/6));
    int count = 0;

    while (true) {
        int n = pow(i, 6);
        
        if (a <= n && b >= n) count++;
        else break; 
        i++;
    }
    cout << count;
}
