#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

set<int> adjList[300001];
int P[300001];
bool craftable_ingredients[300001];

bool i_have_ingredient(int ing) {

    // if i can already craft it, then don't bother
    if (craftable_ingredients[ing]) return false;
    craftable_ingredients[ing] = true;

    // ingredient 0 is a special ingredient that gets called when ingredient 1 is cooked
    if (ing == 0) return true;

    // stores what i can cook with this ingredient
    set<int> nodes = adjList[ing];

    // Go to its parent node
    if (nodes.empty()) return false;
    int parent_idx = *nodes.begin();
    set<int>& parent = adjList[parent_idx];
    parent.erase(ing);

    // i have all the prerequisites to cook it
    if (parent.size() == 1) {
        return i_have_ingredient(parent_idx);
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, D;
    cin >> N >> M >> D;

    for (int i = 0; i < M; i++) {
        int target, num_req;
        cin >> target >> num_req;
        while (num_req--) {
            int ingredient;
            cin >> ingredient;
            
            adjList[target].insert(ingredient);
            adjList[ingredient].insert(target);
        }
    }
    // this is just for coding magic
    adjList[0].insert(0);
    adjList[1].insert(0);
    for (int i = 0; i < D; i++) {
        cin >> P[i];
    }

    for (int d = 0; d < D; d++) {
        if (i_have_ingredient(P[d])) {
            cout << d + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
