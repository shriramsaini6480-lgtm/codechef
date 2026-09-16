#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<int> P(N);
    vector<int> pos(N + 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        pos[P[i]] = i;
    }
    
    // adj[u] will store directed edges u -> v
    vector<vector<int>> adj(N + 1);
    vector<int> in_degree(N + 1, 0);
    
    // Add directed edges for adjacent values |x - y| == 1
    for (int v = 1; v < N; ++v) {
        int u1 = v;
        int u2 = v + 1;
        
        // Preserve relative order between consecutive integers
        if (pos[u1] < pos[u2]) {
            adj[u1].push_back(u2);
            in_degree[u2]++;
        } else {
            adj[u2].push_back(u1);
            in_degree[u1]++;
        }
    }
    
    // Min-heap for greedy topological sort (lexicographically smallest first)
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        
        result.push_back(u);
        
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                pq.push(v);
            }
        }
    }
    
    // Print the result
    for (int i = 0; i < N; ++i) {
        cout << result[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}