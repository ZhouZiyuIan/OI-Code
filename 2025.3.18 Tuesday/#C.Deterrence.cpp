#include<stdio.h>
#include<string.h>
int n,a,b,cnt,head[201],vis[401],tmp[401],tmp1,tmp2,ans;
int max(int a,int b){return a>b?a:b;}
struct edg{
	int nxt,to,from;
}e[401];
void add(int from,int to,int dis){
	e[++cnt].nxt=head[from];
	e[cnt].to=to;
	e[cnt].from=from;
	head[from]=cnt;
}
void dfs(int cur){
    for(int i=head[cur];i;i=e[i].nxt){
        int u=e[i].from,v=e[i].to;
        if(!vis[v]){
            vis[v]=1;
            dfs(v);
            tmp1=max(tmp1,tmp[u]+tmp[v]+1);
            tmp[u]=max(tmp[u],tmp[v]+1);
        }
    }
}
main(){
    scanf("%d",&n);n--;
    while(n--)scanf("%d%d",&a,&b),add(a,b,1),add(b,a,1);
    for(int i=1;i<=cnt;i+=2){
        memset(vis,0,sizeof(vis));
        memset(tmp,0,sizeof(tmp));
        int v1=e[i].to,v2=e[i+1].to;
        vis[v1]=vis[v2]=1;
        tmp1=0;
        dfs(v1);
        tmp2=tmp1;
        tmp1=0;
        dfs(v2);
        ans=max(ans,tmp1*tmp2);
    }
    printf("%d",ans);
}