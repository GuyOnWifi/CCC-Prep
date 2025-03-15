// CCO '98 P5 - Text Segmentation

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

unordered_set<string> dict;

// let dp[i] represent the nmber of words needed to get to i
int dp[101];
int parent[101];

vector<string> output;
void print_ans(int idx, string s) {
    if (idx <= 0) return;
    int l = idx - parent[idx];
    print_ans(parent[idx], s);
    output.push_back(s.substr(idx - l, l));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        dict.insert(s);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 101; j++) {
            dp[j] = 10000;
        }
        dp[0] = 0;
        for (int j = 1; j <= s.length(); j++) {
            for (int k = 0; k < j; k++) {
                if (dp[k] == 10000) continue;
                string ss = s.substr(k, j - k);
                if (dict.count(ss)) {
                    if (dp[k] + 1 < dp[j]) {
                        dp[j] = dp[k] + 1;
                        parent[j] = k;
                    }
                }
            }
        }
        output.clear();
        if (dp[s.length()] == 10000) {
            cout << "***" << s << endl;
            continue;
        }
        print_ans(s.length(), s);
        for (int i = 0; i < output.size() - 1; i++) {
            cout << output[i] << " ";
        }
        cout << output[output.size() - 1] << endl;
    }
}