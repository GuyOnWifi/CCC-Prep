#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int cups[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        cups[a] += c;
        cups[b + 1] -= c;
    }
    
    int L;
    cin >> L;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++) {
            cups[j] = cups[j] + cups[j - 1];
        }
    }

    
    int most = 0;
    int i = 1;
    int j = 1;
    while (j < N) {
        int sum = cups[j] - cups[i - 1];
        if (sum <= L) {
            most = max(most, j - i + 1);
            j++;
        } else {
            i++;
        }
    }

    cout << most;

}
