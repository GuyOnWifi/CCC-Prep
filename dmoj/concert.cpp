#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int position[200000];
int speed[200000];
int hearing[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int pos, spd, hear;
        cin >> pos >> spd >> hear;

        position[i] = pos;
        speed[i] = spd;
        hearing[i] = hear;
    }

    
}
