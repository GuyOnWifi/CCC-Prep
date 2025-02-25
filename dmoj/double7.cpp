#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;


    vector<char> moves;
    for (int i = 0; i < N; i++) {
        char move;
        cin >> move;
        moves.pb(move);
    }

    int ammo_friend = 0;
    int ammo_me = 0;
    int score = 0;

    for (int i = 0; i < moves.size(); i++) {
        if (moves[i] == 'B') {
            // R
            ammo_me++;
        } 
        if (moves[i] == 'R') {
            ammo_friend++;
            if (ammo_me > 0) {
                // F
                score++;
                ammo_me--;
            } else {
                // R
                ammo_me++;
            }
        }
        if (moves[i] == 'F') {
            if (ammo_friend > 0) {
                ammo_friend--;
                // B
            } else {
                // No ammo
                if (ammo_me > 0) {
                    // F
                    score++;
                    ammo_me--;
                } else {
                    // R
                    ammo_me++;
                }
            }
        }

    }
    cout << score;

}
