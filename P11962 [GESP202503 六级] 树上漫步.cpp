#include<stdio.h>
int n,from,to,head[200001],cnt,num[200001],vis,typcnt[3];
struct edg{
	int nxt,v;
}e[400001];
void add(int from,int to){
	e[++cnt].nxt=head[from];
	e[cnt].v=to;
	head[from]=cnt;
}
void dfs(int x,int typ){
	++typcnt[num[x]=(typ&1?1:2)];
	if(++vis==n)return;
	for(int i=head[x];i;i=e[i].nxt)if(!num[e[i].v])dfs(e[i].v,typ+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&from,&to);
		add(from,to);
		add(to,from);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)printf("%d ",typcnt[num[i]]);
}
