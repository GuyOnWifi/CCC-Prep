#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> piece;

    for (int i = 0; i < M; i++) {
        vector<int> temp;
        for (int j = 0; j < N; j++) {
            int note;
            cin >> note;
            temp.pb(note);
        }
        piece.pb(temp);  
    }

    int pks = 0;
    for (auto notes : piece)  {
        sort(notes.begin(), notes.end());

        int s = 0;
        int e = 1;
        while (s < e) {
            int diff = notes[]
            if ()
        }
        
    }
    

    cout << pks;
}
