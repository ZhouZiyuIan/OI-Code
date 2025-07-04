#include<stdio.h>
#include<queue>
#include<utility>
#include<string.h>
typedef long long ll;
using namespace std;
ll n,m,s,u,v,w,l,cnt,head[200001],dis[200001],vis[200001];
struct edg{
	ll nxt,to,dis;
}e[600001];
priority_queue<pair<int,int> >q;
void add(ll from,ll to,ll dis){
	e[++cnt].nxt=head[from];
	e[cnt].to=to;
	e[cnt].dis=dis;
	head[from]=cnt;
}
void dijkstra(){
    for(ll i=1;i<=n;i++)dis[i]=9223372036854775807ll;
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        ll u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(ll i=head[u];i;i=e[i].nxt){
            ll v=e[i].to;
            ll w=e[i].dis;
            if(dis[v]>dis[u]+w){
            	dis[v]=dis[u]+w;
            	q.push(make_pair(-dis[v],v));
            }
        }
    }
}
main(){
	scanf("%lld%lld",&n,&m);
	s=0;
	for(ll i=0;i<m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w<<1);
		add(v,u,w<<1);
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&w);
		add(0,i,w);
	}
	dijkstra();
	for(ll i=1;i<=n;i++)printf("%lld ",dis[i]);
}
