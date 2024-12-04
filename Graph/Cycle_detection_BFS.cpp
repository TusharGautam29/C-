#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;

void addEdge(int u, int v, bool dir=true) {
    graph[u].push_back(v);
    if(dir) graph[v].push_back(u);
}

// BFS function to detect a cycle using a parent array
bool bfs(int start, vector<int>& parent) {
    queue<int> q;
    visited.insert(start);
    parent[start] = -1;  // Root node has no parent
    
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Check all neighbors of the current node
        for (int neighbour : graph[node]) {
            // If the neighbor is not visited
            if (visited.count(neighbour) == 0) {
                visited.insert(neighbour);
                parent[neighbour] = node; // Set the current node as the parent of the neighbor
                q.push(neighbour);
            } 
            // If the neighbor is visited and is not the parent, it's a cycle
            else if (parent[node] != neighbour) {
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle found
}

// Function to check if the graph contains a cycle using BFS
bool hasCycle() {
    vector<int> parent(v, -1); // Initialize parent array with -1 (no parent)
    
    // Check each unvisited node for a cycle
    for(int i = 0; i < v; i++) {
        if (!visited.count(i)) {
            if (bfs(i, parent)) {
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle detected
}

int main() {
    cin >> v; // Number of vertices
    int m; // Number of edges
    cin >> m;

    // Read edges and build the graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    // Check if the graph has a cycle
    if (hasCycle()) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
