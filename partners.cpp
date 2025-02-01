#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    map<string, string> partners;

    vector<string> list1;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        list1.pb(name);
    }

    for (int i = 0; i < N; i++) {
        string name1 = list1[i];

        string name2;
        cin >> name2;

        if (partners[name2] != "" && partners[name2] != name1 || name1 == name2) {
            cout << "bad" << endl;
            return 0;
        }

        partners[name1] = name2;

    }

    cout << "good" << endl;

}
