#include <bits/stdc++.h>
using namespace std;
string s;
string ss;
int arr[128];


int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> ss;
    
    for (int i = 0; i < (int)s.length(); ++i) ++arr[s[i]];
    
    char quiet = '-';
    char broken = '-';
    char fix = '-';

    int i = 0, j = 0;
    while (i < (int)ss.length() && j < (int)s.length()) {
        if (ss[i] != s[j]) {
            if (arr[ss[i]]) {
                quiet = s[j++];
                while (j < (int)s.length() && s[j] == s[j - 1]) ++j;
            } else {
                broken = s[j];
                fix = ss[i];
            }
        }
        ++i; ++j;
    }
    
    if (j < (int)s.length()) quiet = s[j];

    cout << broken << " " << fix << '\n';
    cout << quiet << '\n';
    
    
    return 0;
}
