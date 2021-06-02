#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N=205;
vector <int> adj [N];
int color [N];
bool flag;
void BFS (int x)
{
queue <int> q ;
    q.push(x);
    color[x] =  1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if(!color[v])
            {
                q.push(v);
                color[v]= color[u] ==1? 2: 1;
            }
            else if(color[v]==color[u])
            {
                flag=true;
                return ;
            }
        }
    }
}

void init()
{
    for(int i=0;i<N;i++)
    {
        adj[i].clear();
        color[i]=0;
    }
    flag=false;
}
int main ()
{
    int m;
    cin>>m;
    init();
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(0);
    puts(flag ? "NOT BICOLORABLE." : "BICOLORABLE.");
    return 0;
}
