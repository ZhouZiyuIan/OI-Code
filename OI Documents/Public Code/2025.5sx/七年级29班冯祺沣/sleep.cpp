#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
void fre()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
}
const int MAXN=100401;
int n,t;
int a[MAXN],sum[MAXN];
int find(int l,int r,int x)
{
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(x>sum[mid]) l=mid;
		else if(x==sum[mid]) l=r=mid;
		else r=mid;
	}
	return r;
}
signed main()
{
	fre();
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	t=t%sum[n];
	int x=find(1,n,t);
	cout<<x<<" "<<sum[x]-t;
	return 0;
}
