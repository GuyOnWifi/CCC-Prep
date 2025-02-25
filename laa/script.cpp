// WC '18 Finals J2 - Script Doctor

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string res = "";
    int i = 0;
    for (int i = 0; i < s.size(); i++){
        
        if (i < s.size() - 3 && s.substr(i, 4) == "bull") {
            res += "bll";
            i += 3;
        } else {
            res += s[i];
        }
    }
    cout << res << endl;
}
