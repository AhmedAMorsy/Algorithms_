#include<iostream>
#include<vector>

using namespace std;
const int N = 1e3+3, OO = 0x3f3f3f3f;
int n, m, u, v;
vector<int> adj[N];
bool vis[N];

void DFS(int u) {   // O(n+m)
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

/*void DFSMatrix(int u) { // O(n^2)
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
        if (matrix[u][v] && !vis[v]) {
            DFSMatrix(v);
        }
    }
}

void DFSEdgeList(int u) { // O(n*m)
    vis[u] = true;
    for (int i = 0; i < m; i++) {
        if (edgeList[i].first == u) {
            int v = edgeList[i].second;
            if (!vis[v]) {
                DFSEdgeList(v);
            }
        } else if (edgeList[i].second == u) {
            int v = edgeList[i].first;
            if (!vis[v]) {
                DFSEdgeList(v);
            }
        }
    }
}*/

int main() {
   // scanf("%d %d", &n, &m);
    cin>>n>>m;
   for (int i = 0; i < m; i++) {
       // scanf("%d %d", &u, &v);
       cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    return 0;
}