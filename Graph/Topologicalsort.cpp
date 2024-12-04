#include <bits/stdc++.h>
using namespace std;
vector<list<int>> graph; // Adjacency list to represent the graph
int v; // Number of vertices

// Function to add an edge to the graph
void addedge(int a, int b, bool bidir = true) {
    graph[a].push_back(b); // Add directed edge from 'a' to 'b'
    if (bidir) graph[b].push_back(a); // If bidirectional, add edge from 'b' to 'a'
}

// Function to perform topological sort using Kahn's Algorithm
void topoBFS() {
    vector<int> indegree(v, 0); // Array to store the indegree of each vertex

    // Calculate indegrees of all vertices
    for (int i = 0; i < v; i++) {
        for (auto neighbor : graph[i]) indegree[neighbor]++;
    }

    queue<int> q; // Queue to process vertices with zero indegree
    unordered_set<int> vis; // Set to track visited vertices

    // Push all vertices with zero indegree into the queue
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            vis.insert(i);
        }
    }

    // Process the vertices in topological order
    while (!q.empty()) {
        int x = q.front();
        cout << x << " "; // Print the current vertex
        q.pop();

        // Reduce indegree of neighbors and push to queue if indegree becomes zero
        for (auto neighbor : graph[x]) {
            if (!vis.count(neighbor)) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                    vis.insert(neighbor);
                }
            }
        }
    }
}

int main() {
    v = 6; // Define the number of vertices
    graph.resize(v); // Resize the adjacency list to hold all vertices

    // Add directed edges to the graph
    addedge(5, 0, false);
    addedge(5, 2, false);
    addedge(4, 0, false);
    addedge(4, 1, false);
    addedge(2, 3, false);
    addedge(3, 1, false);

    // Perform topological sort and print the result
    topoBFS();

    cout << endl;
    return 0;
}
