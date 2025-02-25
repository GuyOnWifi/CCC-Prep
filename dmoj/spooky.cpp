#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int arr[10000][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, S;
    
    
    for (int i = 0; i < N; i++) {
        int a, b, amnt;
        cin >> a >> b >> amnt;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = amnt;
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < N; j++) {
            if (i < arr[i][0])
        }
    }

}
