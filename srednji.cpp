// COCI '07 Contest 1 #5 Srednji

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int nums[100000];
int median_list[100000];
int psa[100000];

unordered_map<int, vector<int>> seen;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, B;
    cin >> N >> B;
    int idx = 0;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        if (nums[i] < B) {
            median_list[i] = -1;
        } else if (nums[i] > B) {
            median_list[i] = 1;
        } else if (nums[i] == B) {
            idx = i;
        }
    }
    seen[0].push_back(-1);

    // construct the PSA
    psa[0] = median_list[0];
    seen[psa[0]].push_back(0);
    for (int i = 1; i < N; i++) {
        psa[i] = median_list[i] + psa[i - 1];
        seen[psa[i]].push_back(i);
    }

    int ans = 0;
    for (auto it = seen.begin(); it != seen.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: ";

        vector<int> l = it->second;
        auto split = lower_bound(l.begin(), l.end(), idx);
        int i = split - l.begin();
        

        ans += i * (l.size() - i);
        for (auto x : it->second) {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << ans << endl;


}
