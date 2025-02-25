// Arcadia Computing Contest 1 P4 - Cyclic Sorting

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int arr[200001];
bool decr[200001];

int mod(int a, int m) {
    return ((a % m) + m) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        decr[i] = false;
        if (arr[i] > arr[(i + 1) % N]) {
            decr[i] = true;
        }
    }
    
    int num_decr = 0;
    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (decr[i]) {
            num_decr++;
            idx = i % N;
        }
    }

    while (Q--) {
        int a, x;
        cin >> a >> x;
        a--;
        arr[a] = x;

        // update decre
        if (arr[mod(a - 1, N)] > arr[a]) {
            decr[mod(a - 1, N)] = true;
        } else {
            decr[mod(a - 1, N)] = false;
        }

        if (arr[a] > arr[mod(a + 1, N)]) {
            decr[a] = true;
        } else {
            decr[a] = false;
        }
        


        idx++;
        if (num_decr > 1) {
            cout << -1 << endl;
        } else {
            cout << min(idx, N - idx) << endl;
        }
        


    }
}
