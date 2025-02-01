#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    string strings;
    int sign = 1;
    int num = 0;
    bool is_num = false;
    for (char& c : str) {
        if (c >= 'A' && c <= 'Z') {
            if (is_num) {
                cout << strings << " " << (sign == 1 ? "tighten" : "loosen") << " " << num << "\n";
                is_num = false;
                strings = "";
                num = 0;
            }
            strings += c;
        }

        if (c == '+') sign = 1;
        if (c == '-') sign = -1;
        if (c >= '0' && c <= '9') {
            num *= 10;
            num += c - '0';
            is_num = true;
        }
    }
    cout << strings << " " << (sign == 1 ? "tighten" : "loosen") << " " << num << "\n";

}
