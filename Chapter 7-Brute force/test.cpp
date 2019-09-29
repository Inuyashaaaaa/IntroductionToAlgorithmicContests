#include<cstring>
#include<iostream>
using namespace std;
int n,m;
int a[15][15];
int vis[4][30];
int dmax;
bool pan()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]&&!vis[0][i]&&!vis[1][j]&&!vis[2][i+j]&&!vis[3][i-j+10]) return false;
    return true;
}
bool dfs(int cpos,int d)
{
    if(d==dmax)
    {
        if(pan()) return true;
    }
    else
    {
        for(int pos=cpos; pos<=n*m; pos++)
        {
            int i,j;
            if(pos%m==0) j=m;
            else j=pos%m;
            i=(pos-1)/m+1;
            int ca=vis[0][i],cb=vis[1][j],cc=vis[2][i+j],cd=vis[3][i-j+10];
            vis[0][i]=vis[1][j]=vis[2][i+j]=vis[3][i-j+10]=1;
            if(dfs(pos,d+1)) return true;
            vis[0][i]=ca,vis[1][j]=cb,vis[2][i+j]=cc,vis[3][i-j+10]=cd;
        }
    }
    return false;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases=1;
    while(cin>>n&&n)
    {
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        cin>>m;
        char ch;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                cin>>ch;
                if(ch=='X') a[i][j]=1;
                else if(ch=='.') a[i][j]=0;
            }
        for(dmax=0;; dmax++)
            if(dfs(1,0)) break;
        cout<<"Case "<<cases++<<": "<<dmax<<"\n";
    }
}