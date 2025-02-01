#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

int get_time(int time) {
    if ((time >= 420 && time <= 600) || (time >= 300 && time <= 480)) {
        int t_before = max(420 - time, 0);
        int t_during = 600 - time - t_before;
        if (t_before + t_during / 2 >= 120) return t_before + (120 - t_before) * 2;
        return t_before + t_during + (120 - t_before - t_during / 2);
    } else if ((time >= 900 && time <= 1140) || (time >= 780 && time <= 1020)) {
        int t_before = max(900 - time, 0);
        int t_during = 1140 - time - t_before;
        if (t_before + t_during / 2 >= 120) return t_before + (120 - t_before) * 2;
        return t_before + t_during + (120 - t_before - t_during / 2);
    }
    return 120;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    int time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));

    int ans = time + get_time(time);

    printf("%.2i:%.2i", (ans / 60) % 24, ans % 60);
}


