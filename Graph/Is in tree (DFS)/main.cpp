#include <iostream>
#include <vector>

using namespace std;
const long long N=10005;
vector <int> adj[N];
bool vis [N];
int ans;
void DFS (int u)
{
    if(!vis[u])
    {
        ans++;
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
    if(m!=n-1)
    {
        puts("NO");
        return 0;
    }
    DFS(1);
    if(ans!=n)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}
