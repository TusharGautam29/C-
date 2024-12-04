#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;

void addEdge(int u, int v,bool dir=true) {
    graph[u].push_back(v);
    if(dir)graph[v].push_back(u);
}

bool dfs(int curr, int end) {
    if (curr == end) return true;
    visited.insert(curr);
    for (int neighbour : graph[curr]) {
        if (not visited.count(neighbour)) {
            bool result = dfs(neighbour, end);
            if (result) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m; // number of nodes and edges
    graph.resize(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    
    int start, end;
    cin >> start >> end;
    
    if (dfs(start, end)) {
        cout << "Path exists" << endl;
    } else {
        cout << "Path does not exist" << endl;
    }

    return 0;
}
