#include <iostream>
#include <vector>

using namespace std;
const int N=1e3+5;
vector <int> adj[N];
bool vis [N];
int ans;
void DFS (int u)
{
    if(!vis[u])
    {
        vis[u]=true;
        for(auto v : adj[u])
        {
            DFS(v);
        }
    }
}
int main()
{
    int m,n;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    return 0;
}
