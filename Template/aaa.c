#include<stdio.h>
int n,m,i,a,j,b,cnt,head[2000001],vis[2000001],lens;
char s[2000001];
struct edg{
    int v,nxt;
}e[2000001];
void add(int from,int to){
    e[++cnt].nxt=head[from];
    head[from]=cnt;
    e[cnt].v=to;
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
    for(i=1;i<=n;i++){
        a=chk(i);
        b=chk(i+n);
        if(a&&b)s[lens++]='?';
        else if(a)s[lens++]='N';
        else if(b)s[lens++]='Y';
        else{
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    puts(s);
}