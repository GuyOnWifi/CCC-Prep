#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

vector<int> courses[200001];

int in_degree[200001];
deque<int> q;
vector<int> output;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;

        in_degree[i] = c;
        if (in_degree[i] == 0) {
            q.push_back(i);
            output.push_back(i);
        }

        while (c--) {
            int req;
            cin >> req;
            courses[req].push_back(i);
        }
    }

    while (!q.empty()) {
        int top = q.front();
        q.pop_front();

        for (auto x : courses[top]) {
            in_degree[x]--;
            if (in_degree[x] == 0) {
                q.push_back(x);
                output.push_back(x);
            }
        }
    }

    for (auto i : output) {
        cout << i << " ";
    }
    cout << endl;
}
