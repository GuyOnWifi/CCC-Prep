// CCC '24 S3 - Swipe

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int A[300000];
int B[300000];
unordered_map<int, vector<int>> seen;

vector<int> dependencies[300000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        seen[A[i]].push_back(i);
    }
    for (int i = 0; i < N; i++) cin >> B[i];
    

    // compute the dependencies
    int p = 0;
    for (int i = 0; i < N; i++) {
        vector<int> &a = seen[B[i]];
        auto it = lower_bound(a.begin(), a.end(), p); 
        int idx = it - a.begin();
        if (idx == a.size()) {
            cout << "NO" << endl;
            return 0;
        }
        p = a[idx];
        dependencies[p].push_back(i);
    }

    cout << "YES" << endl;
    
    int count = 0;
    vector<pair<int, int>> left_swipes;
    vector<pair<int, int>> right_swipes;
    for (int i = 0; i < N; i++) {
        if (dependencies[i].empty()) continue;
        
        int left = dependencies[i][0];
        int right = dependencies[i][dependencies[i].size() - 1];

        if (left < i) {
            count++;
            left_swipes.push_back({left, i});
        } 

        if (right > i) {
            count++;
            right_swipes.push_back({i, right});
        }
    }

    cout << count << endl;
    for (auto [i, j] : left_swipes) {
        cout << "L " << i << " " << j << endl; 
    }

    reverse(right_swipes.begin(), right_swipes.end());
    for (auto [i, j] : right_swipes) {
        cout << "R " << i << " " << j << endl; 
    }
}