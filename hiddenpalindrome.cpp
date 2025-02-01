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

    int longest = 0;
    for (int i = 0; i < str.length(); i++) {
        for (int j = str.length() - 1; j >= 0; j--) {
            
            if (i > j) break;

            if (str[i] == str[j]) {

                int start = i;
                int end = j;
                int result = j - i + 1;
                while (start < end) {
                    if (str[start] != str[end]) {
                        result = 0;
                        break;
                    }
                    start++;
                    end--;
                }
                longest = max(longest, result);
            }

        }
    }

    cout << longest;
}
