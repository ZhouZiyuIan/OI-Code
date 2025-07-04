#include<bits/stdc++.h>
#define int long long
using namespace std;
struct AC
{
	int l,r;
}a[200005],p[200005],o[200005];
int tot,n,s,r;
bool cmp(AC a,AC b)
{
	return a.l<b.l;
}
int cheak(int mid)
{
	if(mid<r) return 1;
	int u=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].r>=mid) o[++u]=a[i];
	}
	if(u<n/2+1) return 0;
	sort(o+1,o+u+1,cmp);
	int j=s;
	for(int i=u;i>=u-(n/2+1)+1;i--)
	{
		if(o[i].l<mid) j=j-(mid-o[i].l);
		if(j<0) return 0;
	}
	return 1;
}
void solve()
{
	scanf("%lld%lld",&n,&s);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].l,&a[i].r),s-=a[i].l;
	sort(a+1,a+n+1,cmp);
	r=a[n/2+1].l;
	tot=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].l>p[tot].r) p[++tot].l=a[i].l,p[tot].r=0;
		p[tot].r=max(p[tot].r,a[i].r);
	}
	for(int i=1;i<=tot;i++)
	{
		int l=p[i].l,r=p[i].r,ans=0;
		if(cheak(r)) continue;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(cheak(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%lld\n",ans);
		return;
	}
	printf("%lld\n",p[tot].r);
}
signed main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solve();
}
