#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;


vector<int> get_count(string s) {
    vector<int> sizes = {0, 0, 0};
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'L') sizes[0]++;
        if (s[i] == 'M') sizes[1]++;
        if (s[i] == 'S') sizes[2]++;
    }

    return sizes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string seq;
    cin >> seq;

    vector<int> sizes = get_count(seq);
    
    vector<int> l = get_count(seq.substr(0, sizes[0]));
    vector<int> m = get_count(seq.substr(sizes[0], sizes[1]));
    vector<int> s = get_count(seq.substr(sizes[0] + sizes[1], sizes[2]));

    int total_swaps = 0;

    int swaps = min(l[1], m[0]);
    l[1] -= swaps;
    m[0] -= swaps;
    m[1] += swaps;
    l[0] += swaps;
    total_swaps += swaps;

    swaps = min(l[2], s[0]);
    l[2] -= swaps;
    s[0] -= swaps;
    s[2] += swaps;
    l[0] += swaps;
    total_swaps += swaps;

    swaps = min(m[2], s[1]);
    m[2] -= swaps;
    s[1] -= swaps;
    s[2] += swaps;
    m[1] += swaps;
    total_swaps += swaps;
    
    cout << total_swaps + 2 * (l[1] + l[2]);
}
