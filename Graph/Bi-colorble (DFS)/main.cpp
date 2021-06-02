#include <iostream>
#include <vector>

using namespace std;
const long long N=2005;
vector <int> adj[N];
int colored [N];
bool flag;
void DFS (int u,int p)
{
    colored[u]=p;
    for(int v: adj[u])
    {
        if(!colored[v])
        {
            int c;
            if(p==1)
            {
                c=2;
            }
            else
            {
                c=1;
            }
            DFS(v,c);
        }
        else if (colored[u]==colored[v])
        {
            flag=false;
        }
    }
}

void init()
{
    for(int i=0;i<N;i++)
    {
        adj[i].clear();
        colored[i]=0;
    }
    flag=true;
}

int main()
{
    init();
    int m,n;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!colored[i])
        {
            DFS(i,1);
        }
    }
    if(flag)
    {
        puts("The graph is bi colorable");
    }
    else
    {
        puts("The graph isn't bi colorable");
    }
    return 0;
}
