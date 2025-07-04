#include<stdio.h>
int n,m,i,a,j,b,cnt,head[2000001],dfn[2000001],low[2000001],vis[2000001],dfncnt,sccsum,scc[2000001],stk[2000001],top;
struct edg{
    int v,nxt;
}e[2000001];
void add(int from,int to){
    e[++cnt].nxt=head[from];
    head[from]=cnt;
    e[cnt].v=to;
}
void tarjan(int u){
    vis[u]=1;
    stk[++top]=u;
    dfn[u]=low[u]=++dfncnt;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[u]=low[u]<low[v]?low[u]:low[v];
        }
        else if(vis[v])low[u]=low[u]<dfn[v]?low[u]:dfn[v];
    }
    if(dfn[u]==low[u]){
        sccsum++;
        while(stk[top]!=u){
            scc[stk[top]]=sccsum;
            vis[stk[top--]]=0;
        }
        scc[stk[top]]=sccsum;
        vis[stk[top--]]=0;
    }
}
void dfs(int u){
    vis[u]=1;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(!vis[v])dfs(v);
    }
}
int chk(int u){
    for(int i=0;i<=(n<<1);i++)vis[i]=0;
	dfs(u);
    for(int i=1;i<=n;i++)if(vis[i]&&vis[i+n])return 0;
    return 1;
}
main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d %c %d %c",&i,&a,&j,&b);
        a=(a=='Y');
        b=(b=='Y');
        add(i+n*(a^1),j+n*(b&1));
        add(j+n*(b^1),i+n*(a&1));
    }
    for(i=1;i<=(n<<1);i++)if(!dfn[i])tarjan(i);
    for(i=1;i<=n;i++){
        a=chk(i);
        b=chk(i+n);
        if(a&&b)putchar('?');
        else if(a)putchar('N');
        else if(b)putchar('Y');
        else{
            puts("IMPOSSIBLE");
            return 0;
        }
    }
}
