#include<stdio.h>
#include<stdarg.h> 
#include<queue>
#include<stdbool.h>
using namespace std;
int a,b,c,d,e,m,n,l,r;
bool vis[500001];
long long dis[500001];
struct edg{
	int nxt,to,dis;
}e[500001];
priority_queue<pair<int,int> >q;
void add(int from,int to,int dis){
	e[++cnt].nxt=head[from];
	e[cnt].to=to;
	e[cnt].dis=dis;
	head[from]=cnt;
}
void dijkstra(int s,int e){
    for(int i=1;i<=n+1;i++)dis[i]=9223372036854775807ll;
    dis[s]=0;
    e++;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            int w=e[i].dis;
            if(dis[v]>dis[u]+w){
            	dis[v]=dis[u]+w;
            	q.push(make_pair(-dis[v],v));
            }
        }
    }
    return dis[e];
}
int main(){
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)!=EOF){
        n=a+b+c+d+e;b+=a;c+=b;d+=c;e+=d;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&l,&r);
            add(l,r+1,r-l+1);
			add(r+1,l,r-l+1);
        }
        printf("%d\n",min(1,2));
    }
}
