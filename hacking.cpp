#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

double nume[200000];
double denom[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> nume[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> denom[i];
    }

    vector<pair<double, int>> vec; 
    for (int i = 0; i < N; i++) {
        vec.pb(make_pair(((nume[i] + 1) / (denom[i] + 1) - nume[i] / denom[i]), i));
    }
    
    sort(vec.begin(), vec.end());

    while (K--) {

        double val = vec[vec.size() - 1].first;
        int idx = vec[vec.size() - 1].second;
s
        nume[idx] += 1;
        denom[idx] += 1;

        vec[vec.size() - 1] = make_pair(((nume[idx] + 1) / (denom[idx] + 1) - nume[idx] / denom[idx]), idx);
    }
    

    double avg = 0;
    for (int i = 0; i < N; i++) {
        avg += nume[i] / denom[i];
    }

    avg = avg / N;

    std::cout << std::setprecision(100);
    cout << avg * 100;
}
