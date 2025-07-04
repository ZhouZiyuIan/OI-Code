#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n;
ll s,ans;
struct NUM
{
	ll l,r;
}a[N];
bool cmp(NUM x,NUM y)
{
	if(x.l<y.l) return 1;
	if(x.l>y.l) return 0;
	if(x.r<y.r) return 1;
	return 0;
}
void ef(ll l,ll r)
{
	while(l<=r)
	{
		ll mid=(l+r)/2;
		int num=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i].l<=mid&&mid<=a[i].r)
			{
				num++;
			}
		}
		if(num<n/2+1)
		{
			
		}
	}
}
void dfs(int k,ll sum,ll lst,ll mid)
{
	if(k>n)
	{
		ans=max(ans,mid);
		return;
	}
	if(ans>mid) return;
	for(int i=a[k].l;i<=a[k].r;i++)
	{
		if(sum-i<0) continue;
		if(lst<=i)
		{
//			printf("%d %d %d %d\n",k,i,lst,mid);
			if(k==n/2+1) dfs(k+1,sum-i,i,i);
			else dfs(k+1,sum-i,i,mid);
		}
	}
}
int main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&s);
		ll minn=1e17,maxx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].l,&a[i].r);
			minn=min(a[i].l,minn);
			maxx=max(a[i].r,maxx);
		}
		sort(a+1,a+1+n,cmp);
		ans=0;
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d %d\n",a[i].l,a[i].r);
//		}
//		ef(minn,maxx);
		dfs(1,s,0,0);
		printf("%lld\n",ans);
	}
	
	return 0;
}
