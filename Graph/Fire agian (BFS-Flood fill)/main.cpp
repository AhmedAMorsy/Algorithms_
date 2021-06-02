#include <iostream>
#include <vector>
#include <queue>


using namespace std;
const int N=2005,oo=0x3f3f3f;
int forest [N][N];
vector <pair<int,int>> burn;
int mr[]={1,-1,0,0};
int mc[]={0,0,-1,1};
int n,m;

inline bool isvaild (int r,int c)
{
    return r>=1&&r<=n&&c>=1&&c<=m;
}
void floodfill()
{
    queue<pair<int,int>>q;
    for(auto v : burn)
    {
        forest[v.first][v.second]=0;
        q.push({v.first,v.second});
    }
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nr=r+mr[i];
            int nc=c+mc[i];

            if(isvaild(nr,nc)&&forest[nr][nc]==oo)
            {
                forest[nr][nc]=forest[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
}

int main ()
{
    cin>>n>>m;
    int row=n,col=m;
    int t;
    cin>>t;
    while(t--)
    {
        int i,j;
        cin>>i>>j;
        burn.push_back({i,j});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            forest[i][j]=oo;
        }
    }
    int z=0,x=1,y=1;
    floodfill();
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(forest[i][j]>z)
            {
                z=forest[i][j];
                x=i;
                y=j;
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
