//Shortest path in a weighted graph
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
    pq.push({0, src}); 

    while (!pq.empty()) {
        auto [currDist, u] = pq.top();
        pq.pop();
        if (currDist > dist[u]) continue; 

        for (auto [v, wt] : adj[u]) {
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);
    
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({3, 3});
    adj[3].push_back({4, 1});
    adj[4].push_back({0, 5});

    int src = 0; 
    vector<int> dist = dijkstra(n, adj, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << '\n';
    }

    return 0;
}
