#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pa pair <int,int> 
#define For(i,x,y) for(int i=x;i<=y;i++)
const int M=100101;
const int inf=1e9+7;
int t;
int n,m;
pa a[M];
int c[M];
int ans;
void dfs(int x,int y)
{
	if(x>n)
	{
		sort(c+1,c+1+n);
		ans=max(ans,c[(n>>1)+1]);
		return;
	}
	if(y<a[x].first) return;
	For(i,a[x].first,min(a[x].second,y))
	{
		c[x]=i;
		dfs(x+1,y-i);
		c[x]=0;
	}
}
signed main()
{
//	freopen("payday.in","r",stdin);
//	freopen("payday.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		For(i,1,n) scanf("%lld%lld",&a[i].first,&a[i].second);
		dfs(1,m);
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}

