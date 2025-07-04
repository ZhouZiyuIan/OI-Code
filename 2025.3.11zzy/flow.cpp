#include<stdio.h>
#include<string.h>
int n,m,s,t,u,v,w,cnt,head[500001];
short vis[5001];
struct edg{
	int nxt,to;
    long long dis;
}e[500001];
void add(int from,int to,long long dis){
	e[++cnt].nxt=head[from];
	e[cnt].to=to;
	e[cnt].dis=dis;
	head[from]=cnt;
}
void upd(){
    memset(vis,0,sizeof(vis));
}
int bfs(){return 0;}
main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<m;i++){
        scanf("%d%d%lld",&u,&v,&w);
        add(u,v,w);
        add(v,u,0);
    }
    while(bfs()!=0)upd();
}