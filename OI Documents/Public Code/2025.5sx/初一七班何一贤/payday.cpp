#include<bits/stdc++.h>
#define int long long
#define rd read()
#define gc getchar()
using namespace std;
inline int read()
{
	int x=0,ss=1,ch=gc;
	while((ch<'0'||ch>'9')&&ch!='-')ch=gc;
	if(ch=='-')ss=-1,ch=gc;
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc;
	return x*ss;
}
const int N=200005;
int T,n,s,d;
int h[N],m[N],l[N],r[N],ans;
inline void dfs(int x,int y)
{
	if(y>s)return;
	if(x>n)
	{
		for(int i=1;i<=n;i++)h[i]=m[i];
		sort(h+1,h+n+1);
		ans=max(ans,h[(n>>1)+1]);
		return;
	}
	for(int i=l[x];i<=r[x];i++)m[x]=i,dfs(x+1,y+i);
}
inline void solve()
{
	n=rd,s=rd;ans=0;
	for(int i=1;i<=n;i++)l[i]=rd,r[i]=rd;
	if(n==1){cout<<min(s,r[1])<<'\n';return;}
	dfs(1,0);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	T=rd;while(T--)solve();
	return 0;
}
