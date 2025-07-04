#include<stdio.h>
struct edg{
    int nxt,v,w;
}edge[200002];
int n,m,u,v,w,tot,head[100002],pas[100002];
__int128 dis[100002];
void add(int u,int v,int w){
    edge[++tot].nxt=head[u];
    edge[tot].v=v;
    edge[tot].w=w;
    head[u]=tot;
}
void dfs(int u,__int128 times,int pass){
    pas[u]=pass;
    if(u==n-1)return;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].v;
        if(dis[v]>dis[u]+edge[i].w*times){
            dis[v]=dis[u]+edge[i].w*times;
            dfs(v,times*10,pass+1);
        }
        else if(dis[v]==dis[u]+edge[i].w*times)if(pas[v]>pass+1)dfs(v,times*10,pass+1);
    }
}
void writeInt128(__int128 x){
    if(x<0)x=-x,putchar('-');
    if(x>9)writeInt128(x/10);
    putchar(x%10+'0');
}
void writeInt(int x){
	if(x<0)x=-x,putchar('-');
    if(x>9)writeInt(x/10);
    putchar(x%10+'0');
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)dis[i]=1e9;
    dis[0]=0;
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    dfs(0,1,1);
    writeInt128(dis[n-1]);
    putchar('\n');
    writeInt(pas[n-1]);
}
