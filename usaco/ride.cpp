/*
ID: easonh81
PROG: ride
LANG: C++                 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;

    int ans1 = 1;
    for (char c : a) {
        ans1 *= c - 'A' + 1;
        ans1 %= 47;
    }

    int ans2 = 1;
    for (char c : b) {
        ans2 *= c - 'A' + 1;
        ans2 %= 47;
    }

    fout << ((ans1 % 47) == (ans2 % 47) ? "GO" : "STAY") << endl;
    return 0;
}