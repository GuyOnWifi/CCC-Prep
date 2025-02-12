// CCC '02 S4 - Bridge Crossing

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int M, Q;

string ppl[100];
int times[100];

int child[100];
vector<int> output;

int recurse(int idx, int t) {

    if (idx >= Q) return t;
    
    int min = INT_MAX;
    int num_group = 0;
    for (int i = 1; i <= M; i++) {
        // calc max time
        int slowest = 0;
        for (int j = idx; j < idx + i; j++) {
            slowest = max(slowest, times[j]);
        }
        int result = recurse(idx + i, t + slowest);

        if (result < min) {
            min = result;
            num_group = i;
        }
    }

    child[idx] = idx + num_group;
    return min;
}

void printResult(int i) {
    if (i >= Q) return;
    output.push_back(child[i] - i);
    printResult(child[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> ppl[i];
        cin >> times[i];
    }

    int t = recurse(0, 0);
    cout << "Total Time: " << t << endl;

    printResult(0);
    int idx = 0;
    for (auto x : output) {
        for (int i = 0; i < x; i++) {
            cout << ppl[idx++] << " ";
        }
        cout << endl;
    }
}
