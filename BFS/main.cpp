#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5+4;
int n, m, u, v;
vector<int> adj[N];

bool vis[N];
void BFS(int src) { // O(n+m)
    queue<int> q;

    q.push(src);
    vis[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(1);
    return 0;
}