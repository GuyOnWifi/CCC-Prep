/*
ID: easonh81
PROG: gift1
LANG: C++                 
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> ppl;
vector<string> names;
int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    int N; 
    fin >> N;
    for (int i = 0; i < N; i++) {
        string name;
        fin >> name;
        names.push_back(name);
    }

    for (int i = 0; i < N; i++) {
        string name;
        fin >> name;

        int money, num_ppl;
        fin >> money >> num_ppl;

        ppl[name] -= money;
        for (int i = 0; i < num_ppl; i++) {
            string p;
            fin >> p;
            ppl[p] += (money / num_ppl);
        }

        if (num_ppl == 0) continue;
        ppl[name] += (money % num_ppl);
    }

    for (auto n : names) {
        fout << n << " " << ppl[n] << endl;
    }

    return 0;
}