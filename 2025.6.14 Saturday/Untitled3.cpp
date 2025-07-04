#include<bits/stdc++.h>
#define N 500005
#define int long long
#define rd read()
#define gc pa == pb && (pb = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pb) ? EOF : *pa++
using namespace std;
static char buf[100000], * pa(buf), * pb(buf);
inline int read()
{
	register int x=0,ss=1,s=gc;
	while(!isdigit(s)&&s!='-')s=gc;
	if(s=='-')ss=-1,s=gc;
	while(isdigit(s))x=(x<<1)+(x<<3)+(s^48),s=gc;
	return ss*x;
}
const int V=1000000000;
int n,m,cnt;
int a[N],root=0;
struct node{int ls,rs,sum,siz;}t[N<<2];
inline int New(){t[++cnt]={0,0,0};return cnt;}
inline void pushup(int id)
{
	t[id].sum=t[t[id].ls].sum+t[t[id].rs].sum;
	t[id].siz=t[t[id].ls].siz+t[t[id].rs].siz;
}
inline void modify(int &id,int l,int r,int x)
{
	if(!id)id=New();
	//cout<<id<<' '<<l<<' '<<r<<'\n';
	if(l==r)return t[id].sum+=x,++t[id].siz,void();
	int mid=l+r>>1;
	if(x<=mid)modify(t[id].ls,l,mid,x);
	else modify(t[id].rs,mid+1,r,x);
	pushup(id);
}
inline int ask(int &id,int l,int r,int x)
{
	if(!id)id=New();
	//cout<<id<<' '<<l<<' '<<r<<'\n';
	int mid=l+r>>1;
	if(l==r)return min(x/l,t[id].siz);
	if(t[id].sum<=x)return t[id].siz;
	if(t[t[id].ls].sum>=x)return ask(t[id].ls,l,mid,x);
	return ask(t[id].rs,mid+1,r,x-t[t[id].ls].sum)+t[t[id].ls].siz;
}
inline void solve()
{
	n=rd,m=rd;
	for(int i=1;i<=n;i++)a[i]=rd;
	for(int i=1;i<=n;i++)
	{
		cout<<i-1-ask(root,1,m,m-a[i])<<' ';
		modify(root,1,m,a[i]);
	}
	cout<<'\n';
	for(int i=1;i<=cnt;i++)t[i]={0,0,0};
	cnt=root=0;
}
signed main()
{
	freopen("car123123.in","r",stdin);
	freopen("car.out","w",stdout);
	int T=rd;
	while(T--)solve();
	return 0;
}
