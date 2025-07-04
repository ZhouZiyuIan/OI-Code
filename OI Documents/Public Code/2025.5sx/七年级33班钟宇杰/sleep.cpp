#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],sum;
signed main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	int n,t;
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	t%=sum;
	if(t==0) printf("%lld\n0",n);
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(t-a[i]<=0) printf("%lld\n%lld",i,a[i]-t),exit(0);
			t-=a[i];
		}
	}
}
