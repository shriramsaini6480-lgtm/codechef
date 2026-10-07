#include <bits/stdc++.h>
using namespace std;

int main() {
int T;
cin >> T;
while (T--) {
int N;
cin >> N;
vector<vector<int>> graph(N + 1);
for (int i = 0; i < N - 1; ++i) {
int u, v;
cin >> u >> v;
graph[u].push_back(v);
graph[v].push_back(u);
}
long long invalid = 0;
for (int v = 1; v <= N; ++v) {
int leafChildren = 0;
for (int u : graph[v]) {
if (graph[u].size() == 1) {
++leafChildren;
}
}
invalid += 1LL * leafChildren * (N - 2)- 1LL * leafChildren * (leafChildren - 1) / 2;
        }
for (int v = 1; v <= N; ++v) {
if (graph[v].size() == 2) {
bool hasLeafNeighbor = false;
for (int u : graph[v]) {
if (graph[u].size() == 1) {
hasLeafNeighbor = true;
    }
    }
if (!hasLeafNeighbor) {
++invalid;
    }
    }
    }

 long long total = 1LL * N * (N - 1) * (N - 2) / 6;
cout << total - invalid << '\n';
}
}