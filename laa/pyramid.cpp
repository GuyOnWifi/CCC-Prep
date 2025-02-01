#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    cin >> L;
    
    while (L--) {
        unordered_map<string, int> level;
        vector<string> names;

        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            names.pb(name);
        }

        int highest = 0;
        level[names[n - 1]] = 1;
        
        // beginning
        level[names[0]] = 2;
        string previous = names[0];
        highest = max(highest, level[names[0]] - 1);

        for (int i = 1; i < n; i++) {
            if (!level[names[i]]) {
                level[names[i]] = level[previous] + 1;
                highest = max(highest, level[names[i]] - 1);
            }

            previous = names[i];
        }

        cout << n * 10 - highest * 20 << "\n";
    }
}
