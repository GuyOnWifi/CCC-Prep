#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int month, day;
    cin >> month;
    cin >> day;

    if (month < 2) cout << "Before";
    else if (month > 2) cout << "After";
    else if (day < 18) cout << "Before";
    else if (day > 18) cout << "After";
    else if (day == 18) cout << "Special";
    
}
