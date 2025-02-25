#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
bool visited[10000];

int main() {
    int start;

    deque<int> q;
    q.push_back(start);
    visited[start] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop_front();

        for (auto x : graph[top]) {
            if (visited[x]) continue;
            visited[x] = true;
            q.push_back(x);
        }
    }
}