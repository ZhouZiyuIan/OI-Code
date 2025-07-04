#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=50010;
typedef long long ll;
int n,m,k;
ll d[MAXN],a[MAXN],ans[MAXN];
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+(ch-'0'),ch=getchar();
	return s*w;
}
inline ll read_ll()
{
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+(ch-'0'),ch=getchar();
	return s*w;
}
struct edge
{
	int to;
	ll cost;
	edge(int to,ll cost):to(to),cost(cost){}
};
vector<edge>G[MAXN];
typedef pair<ll,int>P;
void dijkstra(int s)
{
	priority_queue<P,vector<P>,greater<P> >q;
	for(register int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
	d[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		P p=q.top();
		q.pop();
		int v=p.second;
		if(d[v]<p.first) continue;
		for(register int i=0;i<G[v].size();i++)
		{
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				q.push(make_pair(d[e.to],e.to));
			}
		}
	}
}
int main()
{
	n=read(),m=read(),k=read();
	while(m--)
	{
		int u=read(),v=read();
		ll w=read_ll(); 
		G[u].push_back(edge(v,w));
		G[v].push_back(edge(u,w));
	}
	dijkstra(n);
	for(register int i=1;i<=n;i++) ans[i]=d[i];
	for(register int i=1;i<=k;i++)
	{
		int pos=read();
		ll x=read_ll();
		G[n+1].push_back(edge(pos,d[pos]-x));
	}
	dijkstra(n+1);
	for(register int i=1;i<n;i++)
	{
		printf("%lld %lld\n",d[i],ans[i]);
	}
//		if(d[i]<=ans[i]) printf("%d\n",1);
//		else printf("%d\n",0);
	return 0;
}
