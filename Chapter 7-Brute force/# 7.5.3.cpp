#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
 
const int maxn = 10000;
int cnt;
int maze[5][maxn];
int x[maxn],y[maxn],n;
char str[maxn];
vector<int> ans;
void get(){
  for(int d=1;d<n;d++){
     int ok=1;
     for(int i=0;i<cnt;i++){
        if(maze[x[i]][y[i]+d]){
          ok=0; break;
        }
     }
     if(ok){
        ans.push_back(d);
     }
  }
  if(ans.empty()) {
      ans.push_back(1);
  }
}
int res;
void dfs(int D,int step){
  if((9-step)*ans[0]+D>=res) return ;
  if(step==9){
    res = D; return ;
  }
  for(int i=0;i<ans.size();i++){
       int ok=1;
       for(int j=0;j<cnt;j++){
        if(maze[x[j]][y[j]+ans[i]+D]){
          ok=0; break;
        }
      }
      if(ok){
        for(int j=0;j<cnt;j++)
            maze[x[j]][y[j]+ans[i]+D]=1;
        dfs(D+ans[i],step+1);
        for(int j=0;j<cnt;j++)
            maze[x[j]][y[j]+ans[i]+D]=0;
      }
  }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d",&n)==1&&n){
        cnt=0;
        ans.clear();
        memset(maze,0,sizeof(maze));
        for(int i=0;i<5;i++){
            scanf("%s",str);
            for(int j=0;j<n;j++){
                if(str[j]=='X'){
                    x[cnt]=i;
                    y[cnt++]=j;
                    maze[i][j] = 1;
                }
            }
        }
        get();
        res = 9*n;
        dfs(0,0);
        printf("%d\n",res+n);
    }
    return 0;
}