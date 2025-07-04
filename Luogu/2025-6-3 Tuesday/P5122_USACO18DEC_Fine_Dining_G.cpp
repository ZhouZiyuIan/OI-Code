//  P5122 [USACO18DEC] Fine Dining G
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<queue>
#include<utility>
using namespace std;
#ifdef _WIN64
#define getchar_unlocked() _fgetc_nolock(stdin)
#define putchar_unlocked(_c) _fputc_nolock((_c),stdout)
#endif
template<typename T>
void read(T&w){
	T f=1;
	w=0;
	char s=getchar_unlocked();
	while(!isdigit(s)){
		if(s=='-')f=-f;
		s=getchar_unlocked();
	}
	do{
		w=(w<<1)+(w<<3)+(s^48);
		s=getchar_unlocked();
	}while(isdigit(s));
	w*=f;
}
void write(int x){
	if(x<0)putchar_unlocked(45);
	if(x>9)write(x/10);
	putchar_unlocked(x%10+48);
}
int cnt,head[50010],n,m,k,a,b,t,vis[50010];
long long dis[50010],dis1[50010],val;
struct edg{
	int nxt,to;
	long long dis;
}e[500001];
priority_queue<pair<int,long long> >q;
void add(int from,int to,int dis){
	e[++cnt].nxt=head[from];
	e[cnt].to=to;
	e[cnt].dis=dis;
	head[from]=cnt;
}
void dijkstra(int s){
    for(register int i=1;i<=n;i++)dis[i]=2147483647,vis[i]=0;
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(register int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            int w=e[i].dis;
            if(dis[v]>dis[u]+w){
            	dis[v]=dis[u]+w;
            	q.push(make_pair(-dis[v],v));
            }
        }
    }
}
int main(){
	freopen("fine.in","r",stdin);
	freopen("fine.out","w",stdout);
	read(n);
	read(m);
	read(k);
	while(m--){
		read(a);
		read(b);
		read(t);
		add(a,b,t);
		add(b,a,t);
	}
	dijkstra(n);
	for(register int i=1;i<=n;++i)dis1[i]=dis[i];
	for(register int i=1;i<=k;++i){
		read(a);
		read(val);
		add(n+1,a,dis[a]-val);
	}
	dijkstra(n+1);
	for(register int i=1;i<n;++i){
		putchar_unlocked(dis[i]<=dis1[i]?49:48);
		putchar_unlocked(10);
	}
}
