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