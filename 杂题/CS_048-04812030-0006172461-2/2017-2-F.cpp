#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int N=100005;
int d[N],dd[N],head[N];
int n1,n2,cnt;
queue<int>q[2];
struct node
{
    int u,v,next;
} edge[N];
void init()
{
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(d,0,sizeof(d));
    memset(dd,0,sizeof(dd));
}
void add(int u,int v)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
inline void deal()
{
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
    for (int i = 1; i <= n1+n2; i++)
    {
        if(dd[i]==0)
        {
            if(i <= n1)
                q[0].push(i);
            else
                q[1].push(i);
        }
    }
}
int topsort(int k)
{
    deal();
    int ans = 0;
    while(!q[k].empty()||!q[k^1].empty())
    {
        while(!q[k].empty())
        {
            int u = q[k].front();
            q[k].pop();
            for (int j=head[u]; j!=-1; j=edge[j].next)
            {
                int v = edge[j].v;
                d[v]--;
                if(d[v]==0)
                {
                    if(v<=n1)
                        q[0].push(v);
                    else
                        q[1].push(v);
                }
            }
        }
        ans++;
        k^=1;
    }
    return ans;
}
int main()
{
    int m,u,v;
    while(~scanf("%d%d%d",&n1,&n2,&m))
    {
        if(n1==0&&n2==0&&m==0)
            break;
        init();
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d",&u,&v);
            add(v,u);
            dd[u]++;
            d[u]++;
        }
        int ans1 = topsort(0);
        for (int i = 1; i <= n1+n2; i++)
            d[i] = dd[i];
        int ans2 = topsort(1);
        int ans=ans1<ans2?ans1:ans2;
        printf("%d\n",ans+1);
    }
    return 0;
}