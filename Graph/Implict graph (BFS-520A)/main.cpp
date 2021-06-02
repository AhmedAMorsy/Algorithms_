#include <iostream>
#include <queue>

using namespace std;
const int N=1e4+5,oo=0x3f3f3f;
int dis[N];
int n,m;

void BFS(int src)
{

    dis[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(2*u<N&&dis[2*u]==oo)
        {
            dis[2*u]=dis[u]+1;
            if(2*u==m)
            {
                return ;
            }
            q.push(2*u);
        }
        if(u-1>0&&dis[u-1]==oo)
        {
            dis[u-1]=dis[u]+1;
            if(u-1==m)
            {
                return ;
            }
            q.push(u-1);
        }
    }
}
int main()
{
    cin>>n>>m;
    fill(dis,dis+N,oo);
    BFS(n);
    cout<<dis[m]<<endl;
    return 0;
}
