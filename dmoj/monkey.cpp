#include <bits/stdc++.h>
#define long long ll

using namespace std;


bool is_monkey(string& txt) {
    while (!txt.empty()) {
        if (txt[0] == 'A') {
            txt.erase(0, 1);
            if (txt[0] == 'N') {
                txt.erase(0, 1);
                if (!is_monkey(txt)) return false;
            }
            return true;
        } else if (txt[0] == 'B') {
            txt.erase(0, 1);
            if (!is_monkey(txt)) return false;
            if (txt[0] != 'S') return false;
            txt.erase(0, 1);
            if (txt[0] == 'N') {
                txt.erase(0, 1);
                if (!is_monkey(txt)) return false;
            }
            return true;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        string txt;
        getline(cin, txt);
        
        if (txt[0] == 'X') {
            return 0;
        }

        if (is_monkey(txt) && txt.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}