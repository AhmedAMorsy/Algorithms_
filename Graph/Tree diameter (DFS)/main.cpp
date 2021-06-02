#include <iostream>
#include <vector>

using namespace std;
const int N=10000+5;
vector<int> adj[N];
int maxdepth,node;

void DFS (int u,int p,int depth)
{
    if(depth>maxdepth)
    {
        maxdepth=depth;
        node=u;
    }
    for(auto v: adj[u])
    {
        if(v!=p)
        {
            DFS(v,u,depth+1);
        }
    }
}

int main ()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,-1,0);
    DFS(node,-1,0);
    cout<<maxdepth<<endl;
    return 0;
}
