#include <iostream>
#include <vector> 
using namespace std;
int find(vector<int>& parent, int x){
  return parent[x]= (parent[x] ==x)? x: find(parent,parent[x]);
}
void unionSets(vector<int>&parent, vector<int>& rank,int a ,int b){
  a=find(parent,a);
  b=find(parent,b);
  if(rank[a]>=rank[b]){
    rank[a]++;
    parent[b]=a;
  }
  else{
    rank[b]++;
    parent[a]=b;
  }
}
int main() {
    int n = 5; // Example size of the set
    vector<int> parent(n), rank(n, 0);

    // Initialize each node as its own parent
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Perform union operations
    unionSets(parent, rank, 0, 1);
    unionSets(parent, rank, 1, 2);
    unionSets(parent, rank, 3, 4);

    // Checking if two elements are in the same set
    cout << "Are 0 and 2 in the same set? " << (find(parent, 0) == find(parent, 2) ? "Yes" : "No") << endl;
    cout << "Are 3 and 4 in the same set? " << (find(parent, 3) == find(parent, 4) ? "Yes" : "No") << endl;
    cout << "Are 0 and 3 in the same set? " << (find(parent, 0) == find(parent, 3) ? "Yes" : "No") << endl;

    return 0;
}
