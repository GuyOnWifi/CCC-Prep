#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;


char arr[2][200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int removed = 0;
    int possible = true;
    for (int i = 0; i < N; i++) {
        if (arr[0][i] == 'S' && arr[1][i] == 'S') removed++;
        arr[0][i+1] == '.';
        arr[1][i+1] == '.';        
        if (removed > 2) possible = false;
    }

    cout << (possible ? "YES" : "NO");
}
