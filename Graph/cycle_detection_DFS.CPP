#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;

void addEdge(int u, int v, bool dir=true) {
    graph[u].push_back(v);
    if(dir) graph[v].push_back(u);
}

// DFS function to check for cycles
bool dfs(int src, int parent) {
    visited.insert(src); // Mark the current node as visited
    
    // Visit all the neighbors of the current node
    for (int neighbour : graph[src]) {
        if (!visited.count(neighbour)) {
            if (dfs(neighbour, src)) {
                return true; // Cycle found
            }
        }
        // If the neighbor is visited and not the parent, a cycle exists
        else if (neighbour != parent) {
            return true; // Cycle found
        }
    }
    return false; // No cycle found
}

// Function to check if the graph contains a cycle
bool hasCycle() {
    // Check each unvisited node for a cycle
    for(int i = 0; i < v; i++) {
        if (!visited.count(i)) {
            if (dfs(i, -1)) {  // -1 as the parent of the starting node
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
