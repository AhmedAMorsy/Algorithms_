#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

const int N=50005;
int parent[N];

int getparent (int u)
{
    if(parent[u]==u)
    {
        return u;
    }
    return parent[u]=getparent(parent[u]);
}

void makeparent (int u,int v)
{
    u=getparent(u);
    v=getparent(v);
    parent[v]=u;
}

int main()
{
    int n,m;
    for(int k=1;cin>>n>>m;k++)
    {
        set<int>s;
        iota(parent,parent+N,0);
        int ans=0;
        if(n==0&&m==0)
        {
            return 0;
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            makeparent(u,v);
        }
        for(int i=1;i<=n;i++)
        {
            s.insert(getparent(i));
        }
        cout<<"Case "<<k<<": "<<s.size()<<endl;
    }
    return 0;
}
