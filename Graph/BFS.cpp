#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include<queue>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;

void addEdge(int u, int v,bool dir=true) {
    graph[u].push_back(v);
    if(dir)graph[v].push_back(u);
}

bool bfs(int start, int end) {
    if (start == end) return true;
    
    queue<int> q;
    q.push(start);
    visited.insert(start);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int neighbour : graph[curr]) {
            if (!visited.count(neighbour)) {
                if (neighbour == end) return true;
                visited.insert(neighbour);
                q.push(neighbour);
            }
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
