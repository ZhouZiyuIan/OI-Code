#include<stdio.h>
typedef long long ll;
ll head[101],cnt,n,m,u,v,w,vis[101],ans=9223372036854775807ll;
ll min(ll a,ll b){return a<b?a:b;}
struct edg{
	ll nxt,to,dis;
}e[501];
void add(ll from,ll to,ll dis){
	e[++cnt].nxt=head[from];
	e[cnt].to=to;
	e[cnt].dis=dis;
	head[from]=cnt;
}
void dfs(ll x,ll cur){
	vis[x]=1;
	if(x==n)ans=min(cur,ans);
	for(ll i=head[x];i;i=e[i].nxt)if(!vis[e[i].to])dfs(e[i].to,cur^(e[i].dis));
	vis[x]=0;
}
main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0);
	printf("%lld",ans);
}
