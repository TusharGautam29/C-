#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rank;

int find(int a) {
    return parent[a] = (parent[a] == a) ? a : find(parent[a]);
}

void uni(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x != y) {
        if (rank[x] >= rank[y]) {
            rank[x]++;
            parent[y] = x;
        } else {
            rank[y]++;
            parent[x] = y;
        }
    }
}

struct edge {
    int src, dst, wt;
};

bool cmp(edge a, edge b) {
    return a.wt < b.wt;
}

int kruskal(vector<edge>& edges, int v) {
    sort(edges.begin(), edges.end(), cmp);
    parent.resize(v);
    rank.resize(v, 0);
    for (int i = 0; i < v; i++) parent[i] = i;

    int edgecount = 0, ans = 0, i = 0;
    while (edgecount < v - 1 && i < edges.size()) {
        edge curr = edges[i];
        if (find(curr.src) != find(curr.dst)) {
            uni(curr.src, curr.dst);
            ans += curr.wt;
            edgecount++;
        }
        i++;
    }
    return ans;
}

int main() {
    int v = 4, e = 5; // Number of vertices and edges
    vector<edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    cout << "Minimum cost of spanning tree: " << kruskal(edges, v) << endl;
    return 0;
}

