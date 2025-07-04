#include<stdio.h>
#include<queue>
#include<utility>
#include<string.h>
using namespace std;
bool vis[500001];
long long dis[500001],ans,a,b,c,d,e,m,n,l,r,cnt,head[500001];
struct edg{
	long long nxt,to,dis;
}edge[500001];
priority_queue<pair<long long,long long> >q;
void add(long long from,long long to,long long dis){
	edge[++cnt].nxt=head[from];
	edge[cnt].to=to;
	edge[cnt].dis=dis;
	head[from]=cnt;
}
inline long long dijkstra(long long s,long long e){
    for(long long i=1;i<=n+1;i++)dis[i]=1e15,vis[i]=0;
    dis[s]=0;
    e++;
    q.push(make_pair(0,s));
    while(!q.empty()){
        long long u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(long long i=head[u];i;i=edge[i].nxt){
            long long v=edge[i].to,w=edge[i].dis;
            if(dis[v]>dis[u]+w){
            	dis[v]=dis[u]+w;
            	q.push(make_pair(dis[v],v));
            }
        }
    }
    return dis[e];
}
int main(){
    while(scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e)&&a){
        n=a+b+c+d+e;b+=a;c+=b;d+=c;e+=d;
        cnt=0; 
        scanf("%lld",&m);
        memset(head,0,n+1);
        for(long long i=0;i<m;i++){
            scanf("%lld%lld",&l,&r);
            add(l,r+1,r-l+1);
			add(r+1,l,r-l+1);
        }
		ans=min(min(dijkstra(a+1,b)+dijkstra(c+1,d),dijkstra(a+1,c)+dijkstra(b+1,d)),dijkstra(a+1,d)+dijkstra(b+1,c));
		if(ans>=1e15)puts("-1");
		else printf("%lld\n",ans);
    }
}
