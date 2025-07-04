#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=N<<1,K=N<<5;
int n;
int h[N],e[M],w[M],ne[M],idx;
int son[K][2],cnt[N],res,t=1;
char str[N];
void add(int a,int b,int c){e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;}
void insert(int x)
{
    int p=1;
    for(int i=30;i>=0;i--)
    {
        int u=((x>>i)&1);//取当前第i位
        if(!son[p][u]) son[p][u]=++t;
        p=son[p][u];
    }
}
void check(int x)
{
    int ans=0,p=1;//ans用来记录
    for(int i=30;i>=0;i--)
    {
        int u=((x>>i)&1);
        if(son[p][u^1]) p=son[p][u^1],ans+=(1<<i);
        //重点：如果当前位有不同的，即if(son[p][u^1])，我们就顺着这条路走。如果没有就执行下面的，继续按照原路走
        else p=son[p][u];//原路继续走
    
    }
    res=max(res,ans);//最后取max
}
void init(int x){insert(x);check(x);}
void dfs(int x,int last)
{
    init(cnt[x]);
    for(int i=h[x];~i;i=ne[i])//搜索父节点
    {
        int j=e[i];
        if(j==last) continue;//这里由于不会原路返回，所以是搜索父节点
        cnt[j]=cnt[x]^w[i];//进行异或
        dfs(j,x);
    }
}
int main()
{
    memset(h,-1,sizeof h);//邻接表初始化
    scanf("%d",&n);
    int a,b,c;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }
    dfs(1,0);
    printf("%d",res);
    return 0;
}