#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

using namespace std;

int arr_n[5001];
int arr_m[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr_n[i];
    } 

    int M;
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> arr_m[i];
    }
}
