#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int n,s;
struct Node
{
	int l,r;
}a[N];
int st[N],top,ans,v[N];
inline void dfs(int x)
{
	if(x==n+1)
	{
		int p=s;
		for(int i=1;i<=n;i++)
			v[i]=st[i],p-=st[i];
		sort(v+1,v+1+n);
		if(p<0) return;
		ans=max(ans,v[n/2+1]);
		return;
	}
	for(int i=a[x].l;i<=a[x].r;i++)
	{
		st[++top]=i;
		dfs(x+1);
		top--;
	}
}
inline void solve()
{
	ans=0;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].r;
	}
	dfs(1);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	int T;cin>>T;
	while(T--) solve();
}
