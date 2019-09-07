#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 6;

double max_room,room;

int num_node;
struct node
{
    double w;
    double left;
    double right;
    node(double c = 0,double a = 0,double b = 0):w(c),left(a),right(b){}
}Node[1<<maxn];//1<<maxn足够，因为这是一棵有maxn层的完全树，而我们要求的树叶只有maxn层的树。
int vis[1<<maxn];

void DFS(int cur)
{
    if(cur == num_node -1 )
    {
        double now_room = Node[2 * (num_node - 1)].left + Node[2 * (num_node - 1)].right;
        if(now_room > max_room && now_room < room)
        {
            max_room = now_room;
        }
    }
    else
    {
        for(int i = 0;i < num_node + cur;i++)//i挑的是左树，j挑的是右树
        {
            for(int j = 0;j < num_node + cur;j++)
            {
                if(i == j)
                    continue;
                if(!vis[i] && !vis[j])
                {
                    //都没有访问过
                    vis[i] = vis[j] = 1;
                    Node[num_node + cur].w = Node[i].w + Node[j].w;
                    double left = Node[j].w / Node[num_node + cur].w;
                    double right = Node[i].w /Node[num_node + cur].w;
                    Node[num_node + cur].left = max(left + Node[i].left,Node[j].left - right);
                    Node[num_node + cur].right = max(right + Node[j].right,Node[i].right - left);
                    DFS(cur + 1);
                    vis[i] = vis[j] = 0;
                }
            }
        }
    }

}



int main()
{freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kase;
    scanf("%d",&kase);
    for(int i = 0;i < kase;i++)
    {
        max_room = 0;
        memset(vis,0,sizeof(vis));
        memset(Node,0,sizeof(Node));
        scanf("%lf%d",&room,&num_node);
        for(int j = 0;j < num_node;j++)
        {
            scanf("%lf",&Node[j].w);
        }
        DFS(0);
        if(max_room == 0)
            printf("-1\n");
        else
            printf("%.15lf\n",max_room);

    }
    return 0;
}